import nltk
import re
import pandas as pd
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk import pos_tag, ne_chunk
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

palavras_teste = ['running', 'ran', 'runs', 'better', 'went', 'studies', 'studying', 'cacti', 'cactus']

"""
Questão 4.1. Aplique stemming (PorterStemmer) e lematização (WordNetLemmatizer)
Questão 4.2. Compare os resultados e identifique casos onde:
a) Stemming é superior
b) Lemmatization é superior
c) Ambos falham
"""

# Aplique stemming (PorterStemmer)
stemmer = PorterStemmer()
stemmed_words = [stemmer.stem(word) for word in palavras_teste]
print("Stemming (PorterStemmer) Result:")
print(stemmed_words)

# Aplique lematização (WordNetLemmatizer)
lemmatizer = WordNetLemmatizer()
lemmatized_words = [lemmatizer.lemmatize(word) for word in palavras_teste]
print("\nLemmatization (WordNetLemmatizer) Result:")
print(lemmatized_words)

# Comparação dos resultados
print("\nComparação dos resultados:")
for original, stemmed, lemmatized in zip(palavras_teste, stemmed_words, lemmatized_words):
    print(f"Original: {original} | Stemming: {stemmed} | Lemmatization: {lemmatized}")

''' Casos onde Stemming é superior:
"running", "ran", "runs" → Stemming: "run" (correto), Lemmatization: "running", "ran", "runs" (incorreto)
'''

''' Casos onde Lemmatization é superior:
# - "better" → Stemming: "better" (incorreto), Lemmatization: "better" (correto)
# - "went" → Stemming: "went" (incorreto), Lemmatization: "went" (correto)
# - "studies", "studying" → Stemming: "studi" (incorreto), Lemmatization: "study" (correto)
# - "cacti", "cactus" → Stemming: "cacti", "cactus" (incorreto), Lemmatization: "cactus", "cactus" (correto)
'''

''' Casos onde ambos falham:
Nenhum caso identificado onde ambos falham, mas em contextos mais complexos, ambos podem falhar, como em palavras com múltiplos significados ou formas irregulares que não são corretamente processadas por nenhum dos métodos.
'''
