# -*- coding: utf-8 -*-
"""
MODELO: RANDOM FOREST (VERSÃO CORRIGIDA)
Trabalho Prático - Previsão de Tráfego Rodoviário
Competição ML @DAA - Edição (2025/2026)

"""

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split, cross_val_score, StratifiedKFold
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import warnings
warnings.filterwarnings('ignore')

print("="*80)
print("MODELO: RANDOM FOREST")
print("="*80)

# ============================================================================
# 1. FUNÇÕES DE PROCESSAMENTO
# ============================================================================

def load_and_clean_data(file_path):
    """Carrega e faz limpeza inicial dos dados"""
    print(f"\n A carregar dados de {file_path}...")
    df = pd.read_csv(file_path, encoding='latin1')
    
    # Remover espaços dos nomes das colunas
    df.columns = df.columns.str.strip()
    
    # Remover espaços de valores de colunas categóricas (apenas se forem strings)
    for col in df.select_dtypes(include=['object']).columns:
        df[col] = df[col].str.strip()
    
    print(f"Shape: {df.shape}")
    return df

def engineer_features(df):
    """Cria novas features a partir dos dados existentes"""
    print("Criando features...")
    
    # Converter record_date para datetime
    df['record_date'] = pd.to_datetime(df['record_date'])
    
    # Features temporais básicas
    df['year'] = df['record_date'].dt.year
    df['month'] = df['record_date'].dt.month
    df['day'] = df['record_date'].dt.day
    df['hour'] = df['record_date'].dt.hour
    df['dayofweek'] = df['record_date'].dt.dayofweek
    df['is_weekend'] = df['dayofweek'].isin([5, 6]).astype(int)
    
    # Features temporais cíclicas - vai dividir o circulo trigonométrico em X partes (24, 7 ou 12)
    df['hour_sin'] = np.sin(2 * np.pi * df['hour'] / 24)
    df['hour_cos'] = np.cos(2 * np.pi * df['hour'] / 24)
    df['dayofweek_sin'] = np.sin(2 * np.pi * df['dayofweek'] / 7)
    df['dayofweek_cos'] = np.cos(2 * np.pi * df['dayofweek'] / 7)
    df['month_sin'] = np.sin(2 * np.pi * df['month'] / 12)
    df['month_cos'] = np.cos(2 * np.pi * df['month'] / 12)
    
    # Categorias de tempo do dia
    def categorize_time_of_day(hour):
        if 7 <= hour <= 9:
            return 'rush_morning'
        elif 12 <= hour <= 14:
            return 'lunch_time'
        elif 17 <= hour <= 19:
            return 'rush_evening'
        elif 0 <= hour <= 5:
            return 'night'
        else:
            return 'regular'
    
    df['time_category'] = df['hour'].apply(categorize_time_of_day)
    time_dummies = pd.get_dummies(df['time_category'], prefix='time')
    df = pd.concat([df, time_dummies], axis=1)

    df.to_csv('./outputs/engineered_features_debug.csv', index=False)
    
    # Tratamento de AVERAGE_CLOUDINESS
    # Converter float/NaN para string primeiro
    df['AVERAGE_CLOUDINESS'] = df['AVERAGE_CLOUDINESS'].fillna('desconhecido')
    df['AVERAGE_CLOUDINESS'] = df['AVERAGE_CLOUDINESS'].astype(str)
    
    cloudiness_mapping = {
        'c�u claro': 'ceu_claro', 'c�u limpo': 'ceu_claro',
        'c�u pouco nublado': 'pouco_nublado',
        'algumas nuvens': 'poucas_nuvens', 'nuvens dispersas': 'poucas_nuvens',
        'nuvens quebrados': 'nublado_parcial', 'nuvens quebradas': 'nublado_parcial',
        'tempo nublado': 'nublado', 'nublado': 'nublado',
        'NULL': 'desconhecido', '': 'desconhecido', 'nan': 'desconhecido'
    }
    df['AVERAGE_CLOUDINESS'] = df['AVERAGE_CLOUDINESS'].replace(cloudiness_mapping)
    
    cloudiness_order = {
        'ceu_claro': 0, 'pouco_nublado': 1, 'poucas_nuvens': 2,
        'nublado_parcial': 3, 'nublado': 4, 'desconhecido': -1
    }
    df['cloudiness_encoded'] = df['AVERAGE_CLOUDINESS'].map(cloudiness_order)
    # Valores não mapeados ficam como -1 (desconhecido)
    df['cloudiness_encoded'] = df['cloudiness_encoded'].fillna(-1)
    
    # Tratamento de AVERAGE_RAIN (CORRIGIDO para lidar com NaN e float)
    # Converter float/NaN para string primeiro
    df['AVERAGE_RAIN'] = df['AVERAGE_RAIN'].fillna('desconhecido')
    df['AVERAGE_RAIN'] = df['AVERAGE_RAIN'].astype(str)
    
    def categorize_rain(value):
        # Garantir que value é string
        value = str(value).lower()
        
        if value in ['null', '', 'desconhecido', 'nan']:
            return 'sem_chuva' # podemos alterar para ver a accuracy
        elif any(x in value for x in ['fraca', 'fraco', 'leve', 'chuvisco']):
            return 'chuva_fraca'
        elif any(x in value for x in ['moderada', 'moderado']):
            return 'chuva_moderada'
        elif any(x in value for x in ['forte', 'pesado', 'pesada', 'trovoada']):
            return 'chuva_forte'
        else:
            return 'chuva_fraca'  # default, talvez mudar para sem_chuva?
    
    df['AVERAGE_RAIN'] = df['AVERAGE_RAIN'].apply(categorize_rain)
    
    rain_order = {'sem_chuva': 0, 'chuva_fraca': 1, 'chuva_moderada': 2, 'chuva_forte': 3}
    df['rain_encoded'] = df['AVERAGE_RAIN'].map(rain_order)

    df.to_csv('./outputs/engineered_features_debug_2.csv', index=False)
    
    # Encoding de LUMINOSITY
    luminosity_order = {'DARK': 0, 'LOW_LIGHT': 1, 'LIGHT': 2}
    df['luminosity_encoded'] = df['LUMINOSITY'].map(luminosity_order)
    # Se houver valores não mapeados, colocar valor neutro
    df['luminosity_encoded'] = df['luminosity_encoded'].fillna(1)
    
    # Features de interação
    df['speed_time_ratio'] = df['AVERAGE_FREE_FLOW_SPEED'] / (df['AVERAGE_FREE_FLOW_TIME'] + 1)
    df['temp_humidity_interaction'] = df['AVERAGE_TEMPERATURE'] * df['AVERAGE_HUMIDITY']
    df['weather_score'] = (df['rain_encoded'] * 2 + df['cloudiness_encoded'].clip(lower=0)) / 10
    df['hour_weekend_interaction'] = df['hour'] * df['is_weekend']

    df.to_csv('./outputs/engineered_features_debug_final.csv', index=False)
    
    return df

def prepare_data(df, features_list, has_target=True):
    """Prepara os dados para modelagem"""
    # Remover colunas sem informação
    cols_to_drop = ['city_name', 'AVERAGE_PRECIPITATION']
    df = df.drop(columns=[c for c in cols_to_drop if c in df.columns])
    
    X = df[features_list].copy()
    
    if has_target:
        y = df['AVERAGE_SPEED_DIFF'].copy()
        return X, y
    else:
        return X

# ============================================================================
# 2. CONFIGURAÇÃO DAS FEATURES
# ============================================================================

FEATURES = [
    'AVERAGE_FREE_FLOW_SPEED', 'AVERAGE_TIME_DIFF', 'AVERAGE_FREE_FLOW_TIME',
    'AVERAGE_TEMPERATURE', 'AVERAGE_ATMOSP_PRESSURE', 'AVERAGE_HUMIDITY', 
    'AVERAGE_WIND_SPEED', 'hour', 'dayofweek', 'month', 'is_weekend',
    'hour_sin', 'hour_cos', 'dayofweek_sin', 'dayofweek_cos', 
    'month_sin', 'month_cos', 'cloudiness_encoded', 'rain_encoded', 
    'luminosity_encoded', 'time_lunch_time', 'time_night', 'time_regular', 
    'time_rush_evening', 'time_rush_morning', 'speed_time_ratio', 
    'temp_humidity_interaction', 'weather_score', 'hour_weekend_interaction'
]

# ============================================================================
# 3. CARREGAR E PROCESSAR DADOS DE TREINO
# ============================================================================

df_train = load_and_clean_data('./DAA-TG/training_data.csv')
df_train = engineer_features(df_train)
X, y = prepare_data(df_train, FEATURES, has_target=True)

# ============================================================================
# 4. SPLIT TREINO/VALIDAÇÃO (ESTRATIFICADO)
# ============================================================================

print("\n" + "="*80)
print("SPLIT TREINO/VALIDAÇÃO")
print("="*80)

X_train, X_val, y_train, y_val = train_test_split(
    X, y, 
    test_size=0.2,      # 20% para validação
    random_state=42,
    stratify=y          # Manter proporção das classes
)

print(f"\nDados de Treino: {X_train.shape[0]} amostras")
print(f"Dados de Validação: {X_val.shape[0]} amostras")

print("\nDistribuição das classes no treino:")
print(y_train.value_counts().sort_index())

print("\nDistribuição das classes na validação:")
print(y_val.value_counts().sort_index())

# ============================================================================
# 5. NORMALIZAÇÃO
# ============================================================================

print("\n" + "="*80)
print("NORMALIZAÇÃO DOS DADOS")
print("="*80)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_val_scaled = scaler.transform(X_val)

print("✓ Dados normalizados com StandardScaler")

# ============================================================================
# 6. TREINAMENTO DO MODELO - RANDOM FOREST
# ============================================================================

print("\n" + "="*80)
print("TREINAMENTO DO RANDOM FOREST")
print("="*80)

# Configuração do modelo
model = RandomForestClassifier(
    n_estimators=200,           # Número de árvores
    max_depth=15,               # Profundidade máxima
    min_samples_split=10,       # Mínimo de amostras para split
    min_samples_leaf=5,         # Mínimo de amostras nas folhas
    max_features='sqrt',        # Número de features por split
    class_weight='balanced',    # Lidar com desbalanceamento
    random_state=42,
    n_jobs=-1,                  # Usar todos os cores
    verbose=0                   # Reduzir output
)

print("\nParâmetros do modelo:")
print(f"  - n_estimators: {model.n_estimators}")
print(f"  - max_depth: {model.max_depth}")
print(f"  - min_samples_split: {model.min_samples_split}")
print(f"  - class_weight: {model.class_weight}")

print("\nTreinando modelo...")
model.fit(X_train_scaled, y_train)
print("✓ Modelo treinado!")

# ============================================================================
# 7. AVALIAÇÃO NO CONJUNTO DE TREINO
# ============================================================================

print("\n" + "="*80)
print("AVALIAÇÃO NO CONJUNTO DE TREINO")
print("="*80)

y_pred_train = model.predict(X_train_scaled)
train_accuracy = accuracy_score(y_train, y_pred_train)

print(f"\nAccuracy (Treino): {train_accuracy:.4f} ({train_accuracy*100:.2f}%)")

# ============================================================================
# 8. AVALIAÇÃO NO CONJUNTO DE VALIDAÇÃO
# ============================================================================

print("\n" + "="*80)
print("AVALIAÇÃO NO CONJUNTO DE VALIDAÇÃO")
print("="*80)

y_pred_val = model.predict(X_val_scaled)
val_accuracy = accuracy_score(y_val, y_pred_val)

print(f"\nAccuracy (Validação): {val_accuracy:.4f} ({val_accuracy*100:.2f}%)")

print("\n" + "-"*80)
print("CLASSIFICATION REPORT (VALIDAÇÃO)")
print("-"*80)
print(classification_report(y_val, y_pred_val))

print("\n" + "-"*80)
print("MATRIZ DE CONFUSÃO (VALIDAÇÃO)")
print("-"*80)
cm = confusion_matrix(y_val, y_pred_val, labels=['None', 'Low', 'Medium', 'High', 'Very_High'])
cm_df = pd.DataFrame(cm, 
                     index=['None', 'Low', 'Medium', 'High', 'Very_High'],
                     columns=['None', 'Low', 'Medium', 'High', 'Very_High'])
print(cm_df)

# ============================================================================
# 9. FEATURE IMPORTANCE
# ============================================================================

print("\n" + "="*80)
print("IMPORTÂNCIA DAS FEATURES")
print("="*80)

feature_importance = pd.DataFrame({
    'feature': FEATURES,
    'importance': model.feature_importances_
}).sort_values('importance', ascending=False)

print("\nTop 15 features mais importantes:")
print(feature_importance.head(15).to_string(index=False))

# Salvar feature importance
feature_importance.to_csv('./outputs/rf_feature_importance.csv', index=False)
print("\n✓ Feature importance salva em 'rf_feature_importance.csv'")

# ============================================================================
# 10. CROSS-VALIDATION (OPCIONAL - AVALIAÇÃO MAIS ROBUSTA)
# ============================================================================

print("\n" + "="*80)
print("CROSS-VALIDATION (5-FOLD ESTRATIFICADO)")
print("="*80)

cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)
print("\nExecutando cross-validation (pode demorar alguns minutos)...")
cv_scores = cross_val_score(model, X_train_scaled, y_train, cv=cv, scoring='accuracy', n_jobs=-1, verbose=0)

print(f"\nAccuracy por fold: {cv_scores}")
print(f"Média: {cv_scores.mean():.4f} (+/- {cv_scores.std()*2:.4f})")

# ============================================================================
# 11. PROCESSAR DADOS DE TESTE E FAZER PREDIÇÕES
# ============================================================================

print("\n" + "="*80)
print("PROCESSANDO DADOS DE TESTE")
print("="*80)

df_test = load_and_clean_data('./DAA-TG/test_data.csv')
df_test = engineer_features(df_test)
X_test = prepare_data(df_test, FEATURES, has_target=False)
X_test_scaled = scaler.transform(X_test)

print(f"Dados de teste: {X_test.shape[0]} amostras")

# Fazer predições
print("\nFazendo predições no conjunto de teste...")
predictions = model.predict(X_test_scaled)

# Criar arquivo de submissão
submission = pd.DataFrame({
    'RowId': range(len(predictions)),
    'Speed_Diff': predictions
})

submission.to_csv('./outputs/submission_random_forest.csv', index=False)

print("\n" + "="*80)
print("SUBMISSÃO CRIADA")
print("="*80)
print(f"✓ Arquivo de submissão: 'submission_random_forest.csv'")
print(f"✓ Total de predições: {len(predictions)}")
print(f"\nDistribuição das predições:")
print(pd.Series(predictions).value_counts().sort_index())

# ============================================================================
# 12. RESUMO FINAL
# ============================================================================

print("\n" + "="*80)
print("RESUMO FINAL - RANDOM FOREST")
print("="*80)
print(f"\n✓ Accuracy Treino: {train_accuracy:.4f} ({train_accuracy*100:.2f}%)")
print(f"✓ Accuracy Validação: {val_accuracy:.4f} ({val_accuracy*100:.2f}%)")
print(f"✓ Cross-Validation (5-fold): {cv_scores.mean():.4f} (+/- {cv_scores.std()*2:.4f})")
print(f"\n✓ Feature mais importante: {feature_importance.iloc[0]['feature']} ({feature_importance.iloc[0]['importance']:.4f})")
print(f"\n✓ Arquivo de submissão: submission_random_forest.csv")
print(f"✓ Pronto para submeter na competição!")

print("\n" + "="*80)
