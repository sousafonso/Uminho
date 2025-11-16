import pandas as pd
import numpy as np
from sklearn.model_selection import StratifiedKFold, cross_val_score, GridSearchCV
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline

callsdata = pd.read_csv('datasets/CallsData.csv')
contractdata = pd.read_csv('datasets/ContractData.csv')

dfCallsdata = pd.DataFrame(callsdata)
dfContractdata = pd.DataFrame(contractdata)

full_data = pd.merge(dfCallsdata, dfContractdata, on=['Area Code', 'Phone'])