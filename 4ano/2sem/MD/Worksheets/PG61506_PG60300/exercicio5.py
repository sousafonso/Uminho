import nltk
import re
import pandas as pd
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk import pos_tag, ne_chunk
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
nltk.download('punkt_tab')
nltk.download('averaged_perceptron_tagger_eng')
              
text = "They are flying planes to Paris for a conference"

#5.1. Execute POS tagging na frase.

words = word_tokenize(text)

pos_tags = pos_tag(words)

print("Original Text:")
print(text)
print("\nPoS Tagging Result:")

for word, pos_tag in pos_tags:
    print(f"{word}: {pos_tag}")


# 5.2. Identifique possíveis ambiguidades gramaticais.
# Nesta frase, "plane" significa avião, mas poderia ser um adjetivo descritivo de uma superfície.
# Também "flying" poderia caracterizar um objeto, animal, etc. capaz de voar, para além de ser um verbo, como é o caso desta frase. 