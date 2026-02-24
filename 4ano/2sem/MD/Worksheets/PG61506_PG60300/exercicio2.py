import nltk
import re
import pandas as pd
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk import pos_tag, ne_chunk
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

texto_complexo = "Dr. Smith went to Washington D.C. on Jan. 15th, 2023. He said: 'Let's meet at 10 a.m. - I'll be there!'"

"""
Questão 2.1. Compare a tokenização por palavras vs. por frases.
Questão 2.2. Identifique os problemas na tokenização padrão com abreviações e pontuação.
Questão 2.3. Crie uma solução com regex personalizado para evitar os problemas identificados.
"""

# Tokenização por palavras
tokens_palavras = word_tokenize(texto_complexo)
print("Tokenização por palavras:")
print(tokens_palavras)

# Tokenização por frases
tokens_frases = sent_tokenize(texto_complexo)
print("\nTokenização por frases:")
print(tokens_frases)

# Problemas na tokenização padrão
# A tokenização por palavras pode dividir abreviações como "Dr." em "Dr" e ".". Além disso, pode dividir "10 a.m." em "10", "a", "m", e ".". A tokenização por frases pode não reconhecer corretamente as frases devido à pontuação, como o uso de apóstrofos e hífens.

# Solução com regex personalizado
def custom_tokenizer(text):
    # Regex para manter abreviações e números com pontos
    pattern = r"\b\w+\.\w+|\b\w+\b|[.,!?'-]"
    return re.findall(pattern, text)

tokens_custom = custom_tokenizer(texto_complexo)
print("\nTokenização personalizada com regex:")
print(tokens_custom)