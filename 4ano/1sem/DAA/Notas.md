# Dados e Aprendizagem Automática
---

## Conceitos

### Ciência de Dados
- Área cientifica que estuda os dados e como extrair conhecimento e significado dos mesmos.
- Analisa conjuntos de dados.
- O produto final é geralmente apresentações e relatórios;
- Um cientista de dados (data scientist) é um investigador que aplica as suas competências para elaborar uma metodologia de investigação e trabalha com a teoria por detrás dos algoritmos

### Aprendizagem Automática (Machine Learning)
- Área que aborda as ferramentas e técnicas de construção de modelos que podem aprender por si próprios através da utilização de dados sem serem explicitamente programados.

- Utiliza dados

- O produto final é geralmente um artefacto de
software

- Um engenheiro de aprendizagem automática (Data Engineer) constrói modelos.

### Aprendizagem Simbólica
- Baseada em regras lógicas e conhecimento explícito.

Ex: árvores de decisão, raciocinio baseado em casos.

### Aprendizagem não simbólica
- Baseada em padrões e dados, como redes neuronais.

Ex: redes neuronais, segmentação de imagem, clustering.

### Aprendizagem supervisionada
Paradigma em que os casos que se usam para aprender incluem informação acerca dos resultados pretendidos, sendo possível estabelecer uma relação entre os valores pretendidos e os valores produzidos pelo sistema. Diz-se supervisionada porque este mapeamento é acompanhado por um algoritmo que compara os valores produzidos com os valores pretendidos, e corrige o sistema de modo a que este produza resultados mais próximos dos pretendidos.

São divididos em:
- **Classificação**: prever categorias (ex.: spam vs. não spam).
- **Regressão**: prever valores contínuos (ex.: preço de casas).

### Aprendizagem não supervisionada
Paradigma em que os casos que se usam para aprender não incluem informação acerca dos resultados pretendidos, sendo necessário estabelecer relações entre os casos de modo a descobrir padrões ou estruturas subjacentes.

São divididos em:
- **Clustering**: agrupar dados semelhantes (ex.: segmentação de clientes).
- **Redução de dimensionalidade**: simplificar dados mantendo características importantes (ex.: PCA).
- **Associação**: descobrir regras de associação entre itens (ex.: análise de cestas de compras).

### Aprendizagem por reforço
Paradigma que, apesar de nao ter informação sobre os resultados pretendidos, permite efetuar uma avaliação sobre se os resultados produzidos são bons ou maus. Os algoritmos utilizam técnicas de auto-alimentação de sinais, com vista a melhorar os resultados, por influência da noção de recompensa.

## Metodologias
Metodologias comuns incluem:
- **SEMMA** (Supervised, Explainable, Minimal, Accurate)
- **CRISP-DM** (Cross-Industry Standard Process for Data Mining): entendimento do negócio, entendimento dos dados, preparação dos dados, modelagem, avaliação, implementação.


Vamos utilizar a seguinte metodologia:
1. Definição do problema
2. Recolha de dados
3. Preparação dos dados
4. Segregação dos dados
5. Treino do modelo
6. Avaliação do candidato
7. Implementação do modelo
8. Monitorização e manutenção

## Data Exploration and Preparation
1. Data quality and exploration;
2. Basic data preparation;
3. Advanced data preparation:
    - Feature scaling;
    - Outlier detection and treatment;
    - Feature selection;
    - Missing value treatment;
    - Nominal Value Discretization;
    - Binning/discretization;
    - Feature engineering;

### Data Preparation
1. Feature Scaling
    - Normalization (Min-Max Scaling);
    Serve para colocar os dados numa escala comum, geralmente entre 0 e 1.
    2. Min-Max Scaling formula:
    \[X_{scaled} = (b-a) \cdot \frac{X - X_{min}}{X_{max} - X_{min}} + a\]
    Onde:
    - \(X\) é o valor original;
    - \(X_{min}\) é o valor mínimo do conjunto de dados;
    - \(X_{max}\) é o valor máximo do conjunto de dados;
    - \(a\) e \(b\) são os novos valores mínimo e máximo desejados;
    - Standardization (Z-score Scaling);
    Serve para transformar os dados para que tenham média 0 e desvio padrão 1.
    2. Z-score Scaling formula:
    \[X_{standardized} = \frac{X - \mu}{\sigma}\]
    Onde:
    - \(X\) é o valor original;
    - \(\mu\) é a média do conjunto de dados;
    - \(\sigma\) é o desvio padrão do conjunto de dados;

2. Outlier Detection and Treatment
    - Z-score method;
    - Box plot method;
    - Knowledge-based method;

### Data quality 
1. Missing values;
2. Duplicates;
3. Noise: modificações (corrupção ou distorção) dos dados devido a limitações tecnológicas, etc...;
4. Outliers;

### Data exploration
1. Tendência central: average, mode, median..
2. Dispersão: range, variance, standard deviation;
3. Distribuição: skewness, kurtosis, Gaussian distribution, Normal distribution;

#### Matriz de correlação
Mede a relação entre duas variáveis. Varia entre -1 e 1.
- 1: correlação positiva perfeita, ou seja, quando uma variável aumenta, a outra também aumenta;
- -1: correlação negativa perfeita, ou seja, quando uma variável aumenta, a outra diminui;
- 0: sem correlação, ou seja, não há relação entre as variáveis;

#### Visualização de dados