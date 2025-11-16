import pandas as pd
import numpy as np
from sklearn.model_selection import StratifiedKFold, cross_val_score, GridSearchCV
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline


def load_and_merge():
	"""Load the two CSVs and merge them on Area Code + Phone."""
	callsdata = pd.read_csv('datasets/CallsData.csv')
	contractdata = pd.read_csv('datasets/ContractData.csv')
	# Defensive strip of column names (sometimes quotes sneak in)
	callsdata.columns = callsdata.columns.str.strip().str.replace('"', '', regex=False)
	contractdata.columns = contractdata.columns.str.strip().str.replace('"', '', regex=False)
	
	dfCallsdata = pd.DataFrame(callsdata)
	dfContractdata = pd.DataFrame(contractdata)
	
	full_data = pd.merge(dfCallsdata, dfContractdata, on=['Area Code', 'Phone'])
	return full_data


def prepare_X_y(df: pd.DataFrame):
	"""Prepare feature matrix X and target y.

	Target: Churn (0/1)
	Features: All except identifier-like fields ('Phone') and the target.
	Categorical features: 'State', 'Area Code' (treated categorically to avoid artificial ordering).
	"""
	df = df.copy()
	# Ensure target is nominal
	y = df['Churn'].astype('category')

	# Columns to drop from features
	drop_cols = ['Churn', 'Phone']
	feature_df = df.drop(columns=drop_cols)

	categorical_cols = ['State', 'Area Code']
	# Ensure they exist (safety)
	categorical_cols = [c for c in categorical_cols if c in feature_df.columns]
	# Cast to string for one-hot encoder
	for c in categorical_cols:
		feature_df[c] = feature_df[c].astype(str)

	numeric_cols = [c for c in feature_df.columns if c not in categorical_cols]

	preprocessor = ColumnTransformer(
		transformers=[
			('cat', OneHotEncoder(handle_unknown='ignore', sparse_output=False), categorical_cols),
		],
		remainder='passthrough'
	)

	return feature_df, y, preprocessor, categorical_cols, numeric_cols


def evaluate_decision_tree(X, y, preprocessor, random_state=42):
	"""Task T2: 10-fold CV accuracy and f1_macro for baseline Decision Tree."""
	clf = DecisionTreeClassifier(random_state=random_state)
	pipe = Pipeline([
		('prep', preprocessor),
		('clf', clf)
	])
	cv = StratifiedKFold(n_splits=10, shuffle=True, random_state=random_state)
	acc_scores = cross_val_score(pipe, X, y, cv=cv, scoring='accuracy')
	f1_scores = cross_val_score(pipe, X, y, cv=cv, scoring='f1_macro')
	results = {
		'accuracy_mean': acc_scores.mean(),
		'accuracy_std': acc_scores.std(),
		'f1_macro_mean': f1_scores.mean(),
		'f1_macro_std': f1_scores.std(),
		'accuracy_scores': acc_scores,
		'f1_macro_scores': f1_scores
	}
	return results


def confusion_matrices(X, y, preprocessor, random_state=42):
	"""Task T3: Obtain per-fold and aggregated confusion matrices (10-fold CV)."""
	cv = StratifiedKFold(n_splits=10, shuffle=True, random_state=random_state)
	pipe = Pipeline([
		('prep', preprocessor),
		('clf', DecisionTreeClassifier(random_state=random_state))
	])
	fold_matrices = []
	y_true_all = []
	y_pred_all = []
	for train_idx, test_idx in cv.split(X, y):
		X_train, X_test = X.iloc[train_idx], X.iloc[test_idx]
		y_train, y_test = y.iloc[train_idx], y.iloc[test_idx]
		pipe.fit(X_train, y_train)
		y_pred = pipe.predict(X_test)
		cm = confusion_matrix(y_test, y_pred, labels=[0, 1])
		fold_matrices.append(cm)
		y_true_all.extend(y_test)
		y_pred_all.extend(y_pred)
	aggregated_cm = sum(fold_matrices)
	report = classification_report(y_true_all, y_pred_all, digits=4)
	return fold_matrices, aggregated_cm, report


def hyperparameter_search(X, y, preprocessor, random_state=42):
	"""Task T4: Grid search over criterion and max_depth; report performance variation."""
	pipe = Pipeline([
		('prep', preprocessor),
		('clf', DecisionTreeClassifier(random_state=random_state))
	])
	param_grid = {
		'clf__criterion': ['gini', 'entropy', 'log_loss'],
		'clf__max_depth': [None, 5, 10, 20, 30]
	}
	cv = StratifiedKFold(n_splits=10, shuffle=True, random_state=random_state)
	grid = GridSearchCV(pipe, param_grid, cv=cv,
						scoring={'accuracy': 'accuracy', 'f1_macro': 'f1_macro'},
						refit='f1_macro', n_jobs=-1)
	grid.fit(X, y)
	results_df = pd.DataFrame(grid.cv_results_)
	summary_cols = [
		'param_clf__criterion', 'param_clf__max_depth',
		'mean_test_accuracy', 'std_test_accuracy',
		'mean_test_f1_macro', 'std_test_f1_macro'
	]
	summary = results_df[summary_cols].sort_values(by='mean_test_f1_macro', ascending=False)
	best_params = grid.best_params_
	best_scores = {
		'best_f1_macro': grid.best_score_,
		'best_accuracy_for_refit': results_df.loc[results_df['rank_test_f1_macro'] == 1, 'mean_test_accuracy'].values[0]
	}
	return summary, best_params, best_scores


def main():
	df = load_and_merge()
	X, y, preprocessor, cat_cols, num_cols = prepare_X_y(df)

	print('--- Dataset Shape ---')
	print(df.shape)
	print('Class distribution (Churn):')
	print(y.value_counts(normalize=True).rename('proportion'))

	# T2
	print('\n=== T2: Baseline Decision Tree (10-fold CV) ===')
	t2_results = evaluate_decision_tree(X, y, preprocessor)
	print(f"Accuracy (mean ± std): {t2_results['accuracy_mean']:.4f} ± {t2_results['accuracy_std']:.4f}")
	print(f"F1_macro (mean ± std): {t2_results['f1_macro_mean']:.4f} ± {t2_results['f1_macro_std']:.4f}")

	# T3
	print('\n=== T3: Confusion Matrices (per fold) ===')
	fold_mats, agg_cm, report = confusion_matrices(X, y, preprocessor)
	for i, cm in enumerate(fold_mats, start=1):
		tn, fp, fn, tp = cm.ravel()
		print(f"Fold {i} Confusion Matrix:\n{cm}\nTN={tn} FP={fp} FN={fn} TP={tp}\n")
	print('Aggregated Confusion Matrix (sum over folds):')
	print(agg_cm)
	print('\nClassification Report (aggregated predictions):')
	print(report)

	# Brief analytical commentary (printed)
	tn, fp, fn, tp = agg_cm.ravel()
	if tp + fn > 0:
		recall_positive = tp / (tp + fn)
	else:
		recall_positive = np.nan
	if tn + fp > 0:
		recall_negative = tn / (tn + fp)
	else:
		recall_negative = np.nan
	print('Observation: recall_negative vs recall_positive shows if the model is biased towards majority class.')
	print(f"Recall (Churn=1): {recall_positive:.4f}; Recall (Churn=0): {recall_negative:.4f}")

	# T4
	print('\n=== T4: Hyperparameter Tuning (criterion, max_depth) ===')
	summary, best_params, best_scores = hyperparameter_search(X, y, preprocessor)
	print('Top configurations (sorted by mean_test_f1_macro):')
	print(summary.head(10).to_string(index=False))
	print('\nBest Params (by f1_macro):', best_params)
	print('Best Scores:', best_scores)
	print('\nVariation Insight: Increasing depth can reduce bias but may raise variance; different criteria (gini/entropy/log_loss) alter impurity calculations leading to small performance differences. Examine std to gauge stability.')


if __name__ == '__main__':
	main()


