import nltk
import re
import pandas as pd
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk import pos_tag, ne_chunk
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

textos = [
"The book is on the table",
"To be or not to be, that is the question",
"The search for the meaning of life is the meaning of life"
]

"""
Questão 3.1. Remova stopwords usando a lista padrão do NLTK.
Questão 3.2. Crie uma função que remova stopwords apenas se aparecerem em mais de 50% dos documentos.
"""

# Remova stopwords usando a lista padrão do NLTK
stop_words = set(stopwords.words('english'))
textos_sem_stopwords = []
for texto in textos:
    tokens = word_tokenize(texto)
    filtered_tokens = [word for word in tokens if word.lower() not in stop_words]
    textos_sem_stopwords.append(" ".join(filtered_tokens))

print("Textos sem stopwords:")

for texto in textos_sem_stopwords:
    print(texto)

# Crie uma função que remova stopwords apenas se aparecerem em mais de 50% dos documentos
def remove_frequent_stopwords(textos):
    # Contar a frequência de cada palavra em todos os documentos
    word_freq = Counter()
    for texto in textos:
        tokens = word_tokenize(texto)
        word_freq.update(tokens)

    # Identificar stopwords que aparecem em mais de 50% dos documentos
    frequent_stopwords = set()
    for word, freq in word_freq.items():
        if freq > len(textos) / 2 and word.lower() in stop_words:
            frequent_stopwords.add(word.lower())

    # Remover as stopwords frequentes dos textos
    textos_filtrados = []
    for texto in textos:
        tokens = word_tokenize(texto)
        filtered_tokens = [word for word in tokens if word.lower() not in frequent_stopwords]
        textos_filtrados.append(" ".join(filtered_tokens))

    return textos_filtrados

textos_filtrados = remove_frequent_stopwords(textos)

print("\nTextos com stopwords frequentes removidas:")

for texto in textos_filtrados:
    print(texto)