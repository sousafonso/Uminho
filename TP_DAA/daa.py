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

'''
    EXTRACTION
'''

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
    print("="*80)
    print("Informações do dataset")
    print("="*80)
    print(df.info())

    print("="*80)
    print("Descrição Estatística")
    print("="*80)
    print(df.describe())

    return df

'''
    CLEANING AND TRANSFORMATION
'''

def data_cleaning(df):

    df.drop(columns=['AVERAGE_PRECIPITATION', 'city_name'], inplace=True)

    cloudiness_mapping = {
        'c�u claro': 'ceu_claro', 'c�u limpo': 'ceu_claro', # c�u claro = c�u limpo -> ceu claro
        'c�u pouco nublado': 'pouco_nublado', # c�u pouco nublado = pouco nublado -> pouco nublado
        'algumas nuvens': 'poucas_nuvens', 'nuvens dispersas': 'poucas_nuvens', # algumas nuvens = nuvens dispersas -> poucas nuvens
        'nuvens quebrados': 'nublado_parcial', 'nuvens quebradas': 'nublado_parcial', # nuvens quebrados = nuvens quebradas -> nublado parcial
        'tempo nublado': 'nublado', 'nublado': 'nublado', # tempo nublado = nublado -> nublado
        'NULL': 'desconhecido', '': 'desconhecido', 'nan': 'desconhecido' # valores desconhecidos -> desconhecido
    }
    df['AVERAGE_CLOUDINESS'] = df['AVERAGE_CLOUDINESS'].replace(cloudiness_mapping)

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

    # Encoding de LUMINOSITY
    luminosity_order = {'DARK': 0, 'LOW_LIGHT': 1, 'LIGHT': 2}
    df['luminosity_encoded'] = df['LUMINOSITY'].map(luminosity_order)
    # Se houver valores não mapeados, colocar valor neutro
    df['luminosity_encoded'] = df['luminosity_encoded'].fillna(1)

    df.to_csv('./DAA-TG/cleaned_training_data.csv', index=False)

    return df


lines = [
    "city_name - nome da cidade em causa;",
    "record_date - o timestamp associado ao registo;",
    "average_speed_diff - a diferença de velocidade corresponde à diferença entre (1.) a velocidade máxima que os carros podem atingir em cenários sem trânsito e (2.) a velocidade que realmente se verifica. Quanto mais alto o valor, maior é a diferença entre o que se está a andar no momento e o que se deveria estar a andar sem trânsito, i.e., valores altos deste atributo implicam que se está a andar mais devagar;",
    "average_free_flow_speed - o valor médio da velocidade máxima que os carros podem atingir em cenários sem trânsito;",
    "average_time_diff - o valor médio da diferença do tempo que se demora a percorrer um determinado conjunto de ruas. Quanto mais alto o valor, maior é a diferença entre o tempo que demora para se percorrer as ruas e o que se deveria demorar sem trânsito, i.e., valores altos implicam que se está a demorar mais tempo a atravessar o conjunto de ruas;",
    "average_free_flow_time - o valor médio do tempo que demora a percorrer um determinado conjunto de ruas quando não há trânsito;",
    "luminosity - o nível de luminosidade que se verificava na cidade do Porto;",
    "average_temperature - valor médio da temperatura para o record_date na cidade do Porto;",
    "average_atmosp_pressure - valor médio da pressão atmosférica para o record_date na cidade do Porto;",
    "average_humidity - valor médio de humidade para o record_date na cidade do Porto;",
    "average_wind_speed - valor médio da velocidade do vento para o record_date na cidade do Porto;",
    "average_cloudiness - o valor médio da percentagem de nuvens para o record_date na cidade do Porto;",
    "average_precipitation - valor médio de precipitação para o record_date na cidade do Porto;",
    "average_rain - avaliação qualitativa do nível de precipitação para o record_date na cidade do Porto."
]

# Imprime cada variável com uma linha em branco entre cada uma
print("\n\n".join(lines))


df = load_and_clean_data('./DAA-TG/training_data.csv')
df = data_cleaning(df)