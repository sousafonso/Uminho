import nltk
import re
import pandas as pd
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk import pos_tag, ne_chunk
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer

texto_bruto = """
RT @user123: I LOVEEEE this product!!! 😍😍 It's amazingg 😱😱
Check it out at https://example.com #awesome #musthave
Can't wait to buy more!!! <3 <3 <3
"""

"""
Execute as seguintes tarefas:
o Converta o texto para minúsculas
o Remova URLs, menções (@user) e hashtags (#)
o Substituia emoções textuais como "<3" por palavras ("heart")
o Remova emojis e caracteres especiais (mantenha pontuação básica)
o Normalize palavras com repetição de caracteres (ex: "LOVEEEE" → "love", "amazingg" → "amazing")
"""

# Converta o texto para minúsculas
normalized_text = texto_bruto.lower()

print(normalized_text)

# Remova URLs, menções (@user) e hashtags (#)
# Remove URLs
text = re.sub(r"http\S+", "", normalized_text)
# Remove @
text = re.sub(r"@\w+", "", text)
# Remove hashtags
text = re.sub(r"#\w+", "", text)

# Substitua emoções textuais como "<3" por palavras ("heart")
text = text.replace("<3", "heart")

# Remova emojis e caracteres especiais (mantenha pontuação básica)
text = re.sub(r"[^\w\s.,!?]", "", text)

# Normalize palavras com repetição de caracteres
def normalize_repeated_characters(text):
    return re.sub(r"(.)\1{2,}", r"\1", text)

text = normalize_repeated_characters(text)

print(text)