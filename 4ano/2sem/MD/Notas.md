# Mineração de Dados

---

## Critérios de Avaliação

- Quizzes e fichas teórico-práticas realizados ao longo das aulas e a pares, sem aviso prévio (50% da nota)
- 1/3 dos quizzes com pior desempenho são removidos
- Teste final individual (50% da nota) com nota minima de 8 valores (18 ou 25 de Maio de 2026)


---

## 3. Text Mining
- **Definição**: Processo de **extrair informações (dados não estruturados) úteis** de grandes volumes de texto.
- **Aplicações**: Análise de sentimentos, classificação de documentos, extração de entidades, etc.
- **Técnicas**: Tokenização, stemming, lematização, análise de frequência, etc. (Inclui NLP + ML + estatísticas)

## 4. NLP (Processamento de Linguagem Natural)
- **Definição**: Subcampo da inteligência artificial que se concentra na interação entre computadores e linguagem humana.
- **Aplicações**: Chatbots, tradução automática, análise de sentimentos, assistentes virtuais, retorno de informação, deteção de spam, autocomplete, sumarização de texto, reconhecimento de fala, correção de escrita, etc.
- **Técnicas**: Análise sintática, análise semântica, reconhecimento de entidades nomeadas, etc (Aplicação de algoritmos de machine learning e deep learning para entender e gerar linguagem natural).
- **Desafios:** Ambiguidade, sinónimos, contexto, ironia/sarcasmo

### 4.1 NLU (Compreensão de Linguagem Natural)
- **Definição**: Subcampo do NLP focado na compreensão do significado e contexto da linguagem humana.
- **Aplicações**: Assistentes virtuais, análise de sentimentos, etc
- **Técnicas**: Análise semântica, análise de sentimentos, reconhecimento de entidades nomeadas, etc (Envolve a interpretação do significado e contexto da linguagem natural, muitas vezes usando técnicas de machine learning e deep learning para entender a intenção por trás das palavras).

### 4.2 NLG (Geração de Linguagem Natural)
- **Definição**: Subcampo do NLP focado na geração de texto em linguagem natural a partir de dados estruturados ou não estruturados.
- **Aplicações**: Resumo automático, geração de relatórios, etc
- **Técnicas**: Modelos de linguagem, redes neurais, etc (Envolve a criação de texto em linguagem natural a partir de dados estruturados ou não estruturados, muitas vezes usando técnicas de machine learning e deep learning para gerar texto coerente e relevante).

### 4.3 Análise lexical
- **Definição**: Estudo das palavras e suas formas, incluindo a tokenização, stemming e lematização.
- **Aplicações**: Pré-processamento de texto, análise de frequência, etc
- **Técnicas**: Tokenização, stemming, lematização, etc (Envolve a análise das palavras e suas formas, incluindo a tokenização, stemming e lematização, para preparar o texto para análise posterior).

### 4.4 Análise sintática
- **Definição**: Estudo da estrutura gramatical das frases, incluindo a análise de dependências (relação entre as palavras) e a análise de constituintes.
- **Aplicações**: Análise de sentimentos, classificação de documentos, etc
- **Técnicas**: Análise de dependências, análise de constituintes, etc (Envolve a análise da estrutura gramatical das frases, incluindo a análise de dependências e a análise de constituintes, para entender a relação entre as palavras e a estrutura das frases).

### 4.5 Análise semântica
- **Definição**: Estudo do significado literal das palavras e frases, incluindo a análise de sentimentos, a análise de tópicos e a análise de entidades nomeadas.
- **Aplicações:** Análise de sentimentos, classificação de documentos, etc
- **Técnicas**: Análise de sentimentos, análise de tópicos, análise de entidades nomeadas, etc (Envolve a análise do significado das palavras e frases, incluindo a análise de sentimentos, a análise de tópicos e a análise de entidades nomeadas, para entender o significado e o contexto da linguagem natural).

### 4.6 Análise de discurso
- **Definição**: Estudo da estrutura e organização do discurso, incluindo a análise de coesão e coerência entre múltiplas frases.
- **Aplicações**: Análise de sentimentos, classificação de documentos, etc
- **Técnicas**: Análise de coesão, análise de coerência, etc (Envolve a análise da estrutura e organização do discurso, incluindo a análise de coesão e coerência, para entender a estrutura e a organização do discurso em linguagem natural).

### 4.7 Análise pragmática
- **Definição**: Estudo do significado contextual da linguagem, incluindo a análise de intenção, ironia e sarcasmo.
- **Aplicações**: Análise de sentimentos, classificação de documentos, etc
- **Técnicas**: Análise de intenção, análise de ironia, análise de sarcasmo, etc (Envolve a análise do significado contextual da linguagem, incluindo a análise de intenção, ironia e sarcasmo, para entender o significado e o contexto da linguagem natural em situações específicas).

### 4.8 NLP pipeline
1. **Coleta de dados**: Recolha de texto (raw text) de fontes como redes sociais, artigos, etc.
2. **Pré-processamento**: Limpeza e preparação do texto (remoção de stop words, tokenização, etc).
3. **Análise lexical**: Estudo das palavras e suas formas (tokenização, stemming, lematização).
4. **Análise sintática**: Estudo da estrutura gramatical das frases (análise de dependências, análise de constituintes).
5. **Análise semântica**: Estudo do significado literal das palavras e frases (análise de sentimentos, análise de tópicos, análise de entidades nomeadas).
6. **Análise de discurso**: Estudo da estrutura e organização do discurso (análise de coesão, análise de coerência).
7. **Análise pragmática**: Estudo do significado contextual da linguagem (análise de intenção, análise de ironia, análise de sarcasmo).
8. **Modelagem**: Aplicação de algoritmos de machine learning ou deep learning para resolver tarefas específicas (classificação, geração de texto, etc).
9. **Avaliação**: Medição do desempenho do modelo usando métricas apropriadas (precisão, recall, F1-score, etc).
10. **Implantação**: Implementação do modelo em um ambiente de produção para uso real.

raw text -> text cleaning -> tokenização -> stopword removal -> stemming/lemmatização -> feature extraction -> NLP tasks (NER, classificação, etc) -> structured output / knowledge

### 4.9 Text cleaning e normalização
1. **Character normalization:** Convertendo caracteres para uma forma padrão (ex: "é" para "e").
2. **Case normalization:** Convertendo todo o texto para minúsculas para evitar distinção entre "Casa" e "casa".
3. **Noise removal:** Removendo pontuação, urls, html tags, caracteres especiais, para evitar que ela interfira na análise (ex: "casa!" para "casa").
4. **Stop word removal:** Removendo palavras comuns que não agregam significado (ex: "de", "a", "o").
5. **Stemming:** Reduzindo palavras à sua raiz (ex: "correr", "correndo" para "corr").
6. **Lematização:** Reduzindo palavras à sua forma base (ex: "correr", "correndo" para "correr").
7. **Tokenização:** Dividindo o texto em unidades menores (tokens), como palavras ou frases (ex: "Eu gosto de NLP" para ["Eu", "gosto", "de", "NLP"]).
8. **Feature extraction:** Convertendo o texto em uma representação numérica para uso em modelos de machine learning (ex: TF-IDF, word embeddings, etc).

### 4.10 Limitações do python nativo
1. **Limited Linguistic Awareness:** O python não compreende o significado das palavras, a estrutura gramatical ou o contexto, o que pode levar a análises superficiais. Por exemplo, o python não consegue identificar "Apple" como uma empresa ou uma fruta sem contexto adicional.
2. **Basic tokenization:** O python nativo pode dividir o texto em palavras, mas não lida bem com expressões idiomáticas, gírias ou palavras compostas. Por exemplo, "New York" pode ser dividido em "New" e "York", perdendo o significado de cidade.
3. **No built-in lemmatization or stemming:** O python nativo não possui ferramentas para reduzir palavras à sua forma base, o que pode levar a análises inconsistentes. Por exemplo, "running" e "ran" seriam tratados como palavras diferentes.
4. **Manual and inefficient cleaning:** O processo de limpeza de texto pode ser demorado e propenso a erros, especialmente para grandes volumes de dados. Por exemplo, remover pontuação ou stop words manualmente pode ser tedioso e sujeito a erros humanos.
5. **Lack of advanced NLP features:** O python nativo não possui recursos avançados de NLP, como análise de sentimentos, reconhecimento de entidades nomeadas ou análise de tópicos, o que limita a profundidade da análise. Por exemplo, o python nativo não pode identificar se um texto expressa uma opinião positiva ou negativa sem ferramentas adicionais.

### 4.11 Tokenização
- **Definição**: Processo de dividir o texto em unidades menores, como palavras ou frases, chamadas de tokens.
- **Aplicações**: Pré-processamento de texto, análise de frequência, etc
- **Técnicas**: Tokenização por palavras, tokenização por frases, tokenização por caracteres, etc (Envolve a divisão do texto em unidades menores, como palavras ou frases, para facilitar a análise posterior).

1. **Word tokenization:** Dividir o texto em palavras (ex: "Eu gosto de NLP" para ["Eu", "gosto", "de", "NLP"]).
2. **Subword tokenization:** Dividir o texto em subpalavras (ex: "unhappiness" para ["un", "happiness"]).
3. **Character tokenization:** Dividir o texto em caracteres (ex: "NLP" para ["N", "L", "P"]).
4. **Sentence tokenization:** Dividir o texto em frases (ex: "Eu gosto de NLP. É incrível!" para ["Eu gosto de NLP.", "É incrível!"]).
5. **Paragraph tokenization:** Dividir o texto em parágrafos (ex: "Eu gosto de NLP.\nÉ incrível!" para ["Eu gosto de NLP.", "É incrível!"]).
6. **Whitespace tokenization:** Dividir o texto com base em espaços em branco (ex: "Eu gosto de NLP" para ["Eu", "gosto", "de", "NLP"]).
7. **Regex tokenization:** Usar expressões regulares para definir padrões de tokenização (ex: usar regex para extrair hashtags de um tweet).
8. **Byte pair encoding (BPE):** Dividir o texto em subpalavras com base na frequência de pares de bytes (ex: Input = ["Low", "lower", "newest", "widest"], Output = ["low", "low", "er", "new", "est", "wid", "est"]).
9. **WordPiece tokenization:** Dividir o texto em subpalavras com base na frequência de palavras (ex: Input = ["unhappiness"], Output = ["un", "happiness"]).
10. **SentencePiece tokenization:** tokenização não supervisionada de texto que trata o texto como uma sequencia de caracteres (ex: Input = ["New York"], Output = ["_New", "_York"]).

### 4.12 Stop word removal
- **Definição**: Processo de remover palavras comuns que não agregam significado ao texto, como "de", "a", "o", etc.
- **Aplicações**: Pré-processamento de texto, análise de frequência, etc
- **Técnicas**: Usar uma lista de stop words pré-definida ou personalizada para remover palavras comuns do texto (Envolve a remoção de palavras comuns que não agregam significado ao texto para melhorar a qualidade da análise).

Remove for:
- Topic modeling
- Document clustering
- Keyword extraction

Keep for:
- Sentiment analysis
- Análise de estilo
- Tradução
- Authorship attribution

### 4.13 Stemming
- **Definição**: Processo de reduzir palavras à sua raiz, removendo sufixos e prefixos, para tratar palavras relacionadas como a mesma palavra (ex: "played", "playing", "plays" para "play").
- **Aplicações**: Pré-processamento de texto, análise de frequência, etc
- **Técnicas**: Usar algoritmos de stemming, como o Porter Stemmer, para reduzir palavras à sua raiz (Envolve a redução de palavras à sua raiz para tratar palavras relacionadas como a mesma palavra, o que pode melhorar a qualidade da análise).

### 4.14 Stemming vs Lematização

| Aspecto | Stemming | Lematização |
| --- | --- | --- |
| Definição | Processo de reduzir palavras à sua raiz, removendo sufixos e prefixos, sem considerar o contexto ou a gramática. | Processo de reduzir palavras à sua forma base, considerando o contexto e a gramática para garantir que a forma base seja uma palavra válida. |
| Técnica | Usa algoritmos de stemming, como o Porter Stemmer, para remover sufixos e prefixos. | Usa dicionários e regras gramaticais para identificar a forma base de uma palavra. |
| Exemplo | "played", "playing", "plays" para "play". | "better" para "good", "running" para "run". |
| Vantagens | Rápido e simples de implementar. | Produz palavras mais precisas e significativas. |
| Desvantagens | Pode produzir palavras não reconhecíveis ou ambíguas. | Pode ser **mais lento** e **complexo** de implementar. |
| Uso recomendado | Quando a velocidade é mais importante do que a precisão, ou quando o texto é informal e contém muitas variações de palavras. | Quando a precisão é importante, ou quando o texto é formal e contém palavras bem definidas. |
| Accuracy | Pode ser menos preciso, pois pode produzir palavras não reconhecíveis ou ambíguas. | Geralmente mais preciso, pois produz palavras mais significativas e reconhecíveis. |

### 4.15 POS tagging (Part-of-Speech tagging)
- **Definição**: Processo de atribuir a cada palavra em um texto uma etiqueta que indica sua categoria gramatical, como substantivo, verbo, adjetivo, etc.
- **Aplicações**: Análise sintática, análise semântica, etc
- **Técnicas**: Usar algoritmos de POS tagging, como o Hidden Markov Model (HMM) ou o Conditional Random Field (CRF), para atribuir etiquetas de POS às palavras em um texto (Envolve a atribuição de etiquetas de categoria gramatical as palavras em um texto para facilitar a análise sintática e semântica).

1. Parts of speech (POS)
2. tagging

### 4.16 NER (Named Entity Recognition)
- **Definição**: Processo de identificar e classificar entidades nomeadas num texto, como pessoas, organizações, locais, datas, etc.
- **Aplicações**: Extração de informações, análise de sentimentos, etc
- **Técnicas**: Usar algoritmos de NER, como o Conditional Random Field (CRF) ou o BiLSTM-CRF, para identificar e classificar entidades nomeadas em um texto (Envolve a identificação e classificação de entidades nomeadas em um texto para facilitar a extração de informações e a análise de sentimentos).

Exemplo:
"Imagine dragons gave a concert in lisbon in 2025"
- "Imagine dragons" -> Entidade
- "Lisbon" -> Local
- "2025" -> Data

### 4.17 Feature extraction: BoW (Bag of Words) representation
- **Definição**: Representação de texto onde cada documento é representado como um vetor de contagem de palavras, ignorando a ordem das palavras e a gramática.
- **Aplicações**: Classificação de texto, análise de sentimentos, etc
- **Técnicas**: Criar um vocabulário de palavras únicas em um corpus e representar cada documento como um vetor de contagem de palavras com base nesse vocabulário (Envolve a representação de texto como um vetor de contagem de palavras, ignorando a ordem e a gramática, para facilitar a análise de texto usando técnicas de machine learning).

Step 1: Example corpus
"I love NLP"
"I love Python"

Step 2: Vocabulary
["I", "love", "NLP", "Python"]

Step 3: BoW representation
"I love NLP" -> [1, 1, 1, 0]
"I love Python" -> [1, 1, 0, 1]

|Sentence|I|love|NLP|Python|
|-|-|-|-|-|
|I love NLP|1|1|1|0|
|I love Python|1|1|0|1|

Em python:
```python
from sklearn.feature_extraction.text import CountVectorizer

corpus = ["I love NLP", "I love Python"]
vectorizer = CountVectorizer()

X = vectorizer.fit_transform(corpus)

print("Matriz esparsa: ", X.toarray())
print("Features: ", vectorizer.get_feature_names_out())
```

### 4.18 Feature extraction: TF-IDF 
- **Definição:** Representação de texto onde cada documento é representado como um vetor de pesos de palavras, onde o peso de cada palavra é calculado com base na frequência da palavra no documento e na frequência da palavra em todo o corpus.
- **Aplicações:** Classificação de texto, análise de sentimentos, etc
- **Técnicas:** Calcular o peso de cada palavra usando a fórmula TF-IDF, onde TF é a frequência da palavra no documento e IDF é a frequência inversa da palavra em todo o corpus (Envolve a representação de texto como um vetor de pesos de palavras, onde o peso de cada palavra é calculado com base na frequência da palavra no documento e na frequência da palavra em todo o corpus, para facilitar a análise de texto usando técnicas de machine learning).

Fórmula TF-IDF:
TF-IDF(w, d, D) = TF(w, d) * IDF(w, D)
- $TF(w, d) = Número de vezes que a palavra w aparece no documento d / Número total de palavras no documento d$
- IDF(w, D) = $log(N / (Número de documentos em D que contêm a palavra w))$

```python
from sklearn.feature_extraction.text import TfidfVectorizer

corpus = ["I love NLP", "I love Python"]
vectorizer = TfidfVectorizer()

X = vectorizer.fit_transform(corpus)

import pandas as pd

df = pd.DataFrame(X.toarray(), columns=vectorizer.get_feature_names_out())
print(df)
```

### 4.19 Feature extraction: N-grams
- **Definição:** Representação de texto onde cada documento é representado como um vetor de contagem de n-grams, onde um n-gram é uma sequência de n palavras consecutivas em um texto.
- **Aplicações:** Classificação de texto, análise de sentimentos, etc
- **Técnicas:** Criar um vocabulário de n-grams únicos em um corpus e representar cada documento como um vetor de contagem de n-grams com base nesse vocabulário (Envolve a representação de texto como um vetor de contagem de n-grams, onde um n-gram é uma sequência de n palavras consecutivas em um texto, para facilitar a análise de texto usando técnicas de machine learning).

```python
from sklearn.feature_extraction.text import CountVectorizer

corpus = ["I love NLP", "I love Python"]
vectorizer = CountVectorizer(ngram_range=(1, 2))  # Unigrams and bigrams
X = vectorizer.fit_transform(corpus)

import pandas as pd

df = pd.DataFrame(X.toarray(), columns=vectorizer.get_feature_names_out())
print(df)
```

Tipos de n-grams:
- **Unigrams:** "I", "love", "NLP", "Python"
- **Bigrams:** "I love", "love NLP", "I love", "love Python"
- **Trigrams:** "I love NLP", "I love Python"

\+ n-grams => + contexto 
\+ n-grams => + dimensionalidade e sparsity

### 4.20 Feature extraction: Vector space model (VSM)
- **Definição:** Representação de texto onde cada documento é representado como um vetor em um espaço de alta dimensionalidade, onde cada dimensão corresponde a uma palavra ou n-gram no vocabulário.
- **Aplicações:** Classificação de texto, análise de sentimentos, etc
- **Técnicas:** Criar um vocabulário de palavras ou n-grams únicos em um corpus e representar cada documento como um vetor em um espaço de alta dimensionalidade, onde cada dimensão corresponde a uma palavra ou n-gram no vocabulário (Envolve a representação de texto como um vetor em um espaço de alta dimensionalidade, onde cada dimensão corresponde a uma palavra ou n-gram no vocabulário, para facilitar a análise de texto usando técnicas de machine learning).

```python 
from sklearn.feature_extraction.text import CountVectorizer

corpus = ["I love NLP", "I love Python"]
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(corpus)

import pandas as pd
df = pd.DataFrame(X.toarray(), columns=vectorizer.get_feature_names_out())
print(df)
```

## 5. NLTK (Natural Language Toolkit)
- **Definição:** Biblioteca de Python para processamento de linguagem natural, que fornece ferramentas para tokenização, stemming, lematização, análise de sentimentos, etc.
- **Aplicações:** Análise de sentimentos, classificação de texto, etc
- **Técnicas:** Usar as ferramentas fornecidas pelo NLTK para realizar tarefas de processamento de linguagem natural, como tokenização, stemming, lematização, análise de sentimentos, etc (Envolve o uso da biblioteca NLTK para realizar tarefas de processamento de linguagem natural, como tokenização, stemming, lematização, análise de sentimentos, etc, para facilitar a análise de texto usando técnicas de machine learning).

**Exemplo completo de pré-processamento de texto usando NLTK:**
```python
import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer

# Baixar recursos necessários
nltk.download('punkt')
nltk.download('stopwords')

# Exemplo de texto
text = "I love NLP! It's amazing. I can't wait to learn more about it."

# Tokenização
tokens = word_tokenize(text)
print("Tokens:", tokens)

# Remoção de stop words
stop_words = set(stopwords.words('english'))
filtered_tokens = [word for word in tokens if word.lower() not in stop_words]
print("Filtered Tokens:", filtered_tokens)

# Stemming
stemmer = PorterStemmer()
stemmed_tokens = [stemmer.stem(word) for word in filtered_tokens]
print("Stemmed Tokens:", stemmed_tokens)
```
