import nltk
import re
import pandas as pd
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk import pos_tag, ne_chunk
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from nltk import word_tokenize, pos_tag, ne_chunk

nltk.download('maxent_ne_chunker_tab')
nltk.download('words')

text = """
    Apple Inc. announced yesterday that CEO Tim Cook will visit Portugal next week.
    The company plans to open a new office in Lisbon with 500 employees.
    Microsoft's Satya Nadella also expressed interest in expanding to Porto.
    The EU Commission approved the deal on January 15, 2024.
"""

# 6.1. Extraia todas as entidades nomeadas || 6.2. Classifique-as por tipo (PESSOA, ORGANIZAÇÃO, LOCAL, DATA)
tokens = word_tokenize(text)
tags = pos_tag(tokens)

entities = ne_chunk(tags)

named_entities = []

for chunk in entities:
    if hasattr(chunk, 'label'):
        entity = " ".join(c[0] for c in chunk)
        named_entities.append((entity, chunk.label()))

print(named_entities)

# 6.3. Crie um DataFrame com as entidades e suas frequências.
tree = ne_chunk(tags)
entities_list = []

for subtree in tree:
    if hasattr(subtree, 'label'):
        entity_name = " ".join([leaf[0] for leaf in subtree.leaves()])
        entity_type = subtree.label()
        entities_list.append((entity_name, entity_type))

df = pd.DataFrame(entities_list, columns=["entidade", "tipo"])
df_freq = df.value_counts().reset_index(name="frequência")

print(df_freq)

# 6.4. Identifique possíveis erros de classificação.
# "Apple" foi classificado como "PESSOA" em vez de "ORGANIZAÇÃO" (e "Inc." foi separado), "Microsoft" foi classificado como PESSOA em vez de ORGANIZAÇÃO, "January 15, 2024" não foi classificado como DATA.
