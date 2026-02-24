import nltk
import re
import pandas as pd
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk import pos_tag, ne_chunk
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

documentos = [
"the cat sat on the mat",
"the dog sat on the log",
"cats and dogs are great pets",
"the mat is for the cat",
"dogs love to sit on logs"
]

"""Questão 7.1. Crie a matriz Bag-of-Words.
Questão 7.2. Calcule a matriz TF-IDF.
Questão 7.3 Compare os pesos das palavras:
o Que método dá mais peso a "cat" no doc 0?
o Que palavra tem maior TF-IDF no doc 4? Porquê?
"""

# Crie a matriz Bag-of-Words
vectorizer_bow = CountVectorizer()
bow_matrix = vectorizer_bow.fit_transform(documentos)
print("Matriz Bag-of-Words:")
print(bow_matrix.toarray())
print("Feature Names (Bag-of-Words):")
print(vectorizer_bow.get_feature_names_out())

# Calcule a matriz TF-IDF
vectorizer_tfidf = TfidfVectorizer()
tfidf_matrix = vectorizer_tfidf.fit_transform(documentos)
print("\nMatriz TF-IDF:")
print(tfidf_matrix.toarray())
print("Feature Names (TF-IDF):")
print(vectorizer_tfidf.get_feature_names_out())

# Compare os pesos das palavras
# Que método dá mais peso a "cat" no doc 0?
index_cat_bow = vectorizer_bow.get_feature_names_out().tolist().index("cat")
index_cat_tfidf = vectorizer_tfidf.get_feature_names_out().tolist().index("cat")
peso_cat_bow_doc0 = bow_matrix[0, index_cat_bow]
peso_cat_tfidf_doc0 = tfidf_matrix[0, index_cat_tfidf]
print(f"\nPeso de 'cat' no doc 0 - Bag-of-Words: {peso_cat_bow_doc0}")
print(f"Peso de 'cat' no doc 0 - TF-IDF: {peso_cat_tfidf_doc0}")

# Qual palavra tem maior TF-IDF no doc 4? Porquê?
tfidf_doc4 = tfidf_matrix[4].toarray()[0]
index_max_tfidf_doc4 = tfidf_doc4.argmax()
palavra_max_tfidf_doc4 = vectorizer_tfidf.get_feature_names_out()[index_max_tfidf_doc4]
print(f"\nPalavra com maior TF-IDF no doc 4: '{palavra_max_tfidf_doc4}' com valor {tfidf_doc4[index_max_tfidf_doc4]}")

# A palavra com maior TF-IDF no doc 4 é "logs" porque aparece no doc 4 e tem uma frequência relativamente alta, mas não é tão comum noutros documentos, o que aumenta seu peso TF-IDF.
