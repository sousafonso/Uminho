# Aprendizagem e Decisão Inteligentes

## Paradigmas de Aprendizagem

 **Aprendizagem automática** : Disciplina de IA que se dedica ao estudo e ao desenvolvimento de algoritmos e programas que permitem dotar o computador da capacidade de efetuar determinada tarefa sem recurso à intervenção humana.

**Aprendizagem**:

- **Com supervisão**: Paradigma de aprendizagem em que os casos que se usam para aprender contêm informação acerca dos resultados pretendidos, sendo possível estabelecer uma relação entre os valores pretendidos e os valores produzidos pelo sistema. A maioria dos algoritmos de machine learning usa aprendizagem com supervisão.

Divide-se em **Classificação** quando os dados são discretos (preto, cinza, branco...) e **Regressão** quando os resultados são contínuos (variação de temperatura ou da luz solar ao longo do dia).
*Ex: Diagnóstico médico, classificação de imagens, fidelização de clientes, deteção de fraude, etc. (Classificação)*

*Ex: Crescimento populacional, previsão de vendas, previsão metereológica, esperança média de vida etc. (Regressão)*

- **Sem supervisão**: Paradigma de aprendizagem em que não são conhecidos resultados sobre os casos, apenas os enunciados dos problemas, tornando necessário a escolha de técnicas/critérios de aprendizagem que avaliem o funcionamento interno do sistema.

Divide-se em **Agrupamento/Segmentação** (clustering) quando se pretende organizar dados em grupos coerentes (agrupar clientes que compram bebidas açucaradas) e **Redução de Dimensionalidade/Associação** quando se pretende conhecer regras que associem o comportamento demonstrado pelos dados (pessoas que compram bebidas açucaradas não compram bebidas alccolicas).
*Ex: Sistemas de recomendação, segmentação de clientes, marketing (Agrupamento/Segmentação)*

*Ex: big data, análise de fatores, compreensão de significados, descoberta de estruturas, seleção de atributos, etc. (Redução de Dimensionalidade/Associação).*

- **Por reforço**: Paradigma de aprendizagem que, apesar de não ter informação sobre os resultados pretendidos, permite efetuar uma avaliação sobre se os resultados produzidos são bons ou maus.

*Ex: Jogos com IA, robótica, decisão em tempo real, tarefas de aprendizagem, aquisição de aptidões.*

## Hard computing vs Soft computing

**Soft computing**: É um conjunto de técnicas que se baseiam na tolerância à incerteza, à imprecisão, à verdade parcial e à aproximação. É uma abordagem mais flexível e adaptativa, que procura soluções aproximadas para problemas complexos.

Sistemas de soft computing incluem:

- Redes Neurais
- Algoritmos Genéticos
- Lógica Fuzzy
- Ant colony
- Raciocínio probabilístico
- Particle swarm optimization

#### Representação do conhecimento

**Simbólica**: Baseia-se na manipulação de símbolos e regras lógicas. Ex: Lógica proposicional, lógica de predicados, sistemas de produção, sistemas de inferência, etc.

**Não simbólica**: Baseia o funcionamento do sistema na capacidade de aprender, generalizando. Resolve problemas com base em conhecimento passado ou dados sobre a resolução de outros problemas.

Atualmente quase todas as ações geram dados.

#### Machine Learning

Paradigma de computação em que a característica essencial é a capacidade de aprender a partir de dados. O sistema é capaz de generalizar a partir de exemplos, permitindo que ele faça previsões ou tome decisões com base em novos dados.

Os algoritmos de machine learning são designados de data-driven, pois são baseados em dados. Eles aprendem a partir de exemplos e generalizam a partir deles, permitindo que o sistema faça previsões ou tome decisões com base em novos dados.

**Exemplos de Sistemas de Aprendizagem Automática**:

- Segmentação
- Classificação
- Árvore de decisão
- Redes neurais
- Algoritmos genéticos : Procedimento iterativo, que mantém uma população de soluções candidatas a um problema, aplicando operadores genéticos (seleção, cruzamento, mutação, purificação, entre outros) para gerar novas soluções. Sendo formada uma nova população de soluções candidatas. A cada incremento de tempo (geração), as estruturas da população corrente são avaliadas na sua capacidade de serem soluções válidas para o domínio do problema, sendo formada uma nova população de soluções
candidatas, baseada na sua avaliação, desenvolvida pela
aplicação de operadores genéticos (seleção, cruzamento, mutação, purificação, entre outros)
- Aprendizagem Simbólica
- Inteligência de grupo
- Máquinas de vetores de suporte
- Raciocínio baseado em casos

### Nós para aplicar no KNIME

- **CSV Reader**
- **File Reader**
- **Scorer**: Avalia o desempenho do modelo de classificação, comparando as previsões com os valores reais.
- **Numeric Scorer**: Avalia o desempenho do modelo de regressão, comparando as previsões com os valores reais.
- **X-Partitioner**: Divide os dados em conjuntos de treino e teste, permitindo a validação cruzada.
- **X-Aggregator**: Agrega os dados de acordo com uma chave comum, permitindo a análise de dados agrupados.
- **Color Manager**: Visualização a distribuição dos dados por classe.
- **Decision Tree Learner**: Cria uma árvore de decisão a partir dos dados de treino.
- **Decision Tree Predictor**: Faz previsões com base na árvore de decisão criada.
- **Partitioning**: Divide os dados em conjuntos de treino e teste. Usa a técnica holdout.
- **Joiner**: Junta dois conjuntos de dados com base em uma chave comum.
- **Column Filter**: Filtra colunas de um conjunto de dados.
- **Column Rename**: Renomeia colunas de um conjunto de dados.
- **Column Filter**: Filtra colunas de um conjunto de dados.

## Big Data

Big data é um termo popularizado para se referir a dados em grande quantidade e complexidade para serem tratados
por abordagens tradicionais de computação.

## Preparação de Dados

O objetivo da preparação de dados consiste em transformar os datasets por forma a que a informação neles contida esteja adequadamente exposta à ferramenta de análise de dados escolhida, de modo a que esta possa extrair o conhecimento pretendido. A preparação de dados é uma etapa fundamental no processo de análise de dados, pois a qualidade dos dados influencia diretamente a qualidade dos resultados obtidos.

Os dados recolhidos do mundo real são incompletos, contêm lixo e podem conter inconsistências.

### Pré-processamento de dados

O pré-processamento de dados é uma etapa fundamental na preparação de dados, pois envolve a limpeza, transformação e normalização dos dados para garantir que eles estejam prontos para análise. O pré-processamento pode incluir as seguintes etapas:

- **Limpeza de dados**: Remoção de dados duplicados, tratamento de valores ausentes (missing values) e correção de erros nos dados.
- **Transformação de dados**: Conversão de dados para um formato adequado para análise, como a normalização ou padronização de variáveis.
- **Redução de dimensionalidade**: Redução do número de variáveis num conjunto de dados, mantendo a maior parte da informação original. Isso pode ser feito por meio de técnicas como PCA (Análise de Componentes Principais) ou seleção de características.

**Tipos de dados**

- **Qualitativos** (categóricos): Dados que representam categorias ou grupos, como sexo (masculino/feminino), cor (vermelho/azul/verde), etc. Esses dados podem ser representados por variáveis nominais (sem ordem) ou ordinais (com ordem).
- **Quantitativos** (numéricos): Dados que representam quantidades ou medidas, como altura, peso, idade, etc. Esses dados podem ser representados por variáveis discretas (valores inteiros) ou contínuas (valores reais).
- **Nominais**: Dados que representam categorias sem uma ordem específica, como cor (vermelho, azul, verde) ou tipo de animal (cachorro, gato, pássaro).
- **Ordinais**: Dados que representam categorias com uma ordem específica, como classificação (bom, médio, ruim) ou nível de escolaridade (fundamental, médio, superior).
- **Categorias**: 

**Discretização de igual largura**: Método de discretização que divide o intervalo de valores em k intervalos de igual largura. Por exemplo, se tivermos um intervalo de 0 a 100 e quisermos dividir em 5 intervalos, teremos os seguintes intervalos: [0, 20], [20, 40], [40, 60], [60, 80], [80, 100].

**Discretização de igual altura**: Método de discretização que divide o conjunto de dados em k intervalos, cada um contendo aproximadamente o mesmo número de instâncias. Por exemplo, se tivermos 100 instâncias e quisermos dividir em 5 intervalos, teremos 20 instâncias em cada intervalo.

**Como tratar dados ausentes?**

- Ignorar os registos onde faltam os dados e lidar, apenas com os dados conhecidos.
  - não aconselhável, pois pode levar a perda de informação importante e se a quantidade de dados em falta em cada atributo for elevada.

- Preencher (manualmente) os dados em falta.
  - é mais trabalhoso preencher ou é mais dificil adivinhar?.

- Preencher os dados em falta com um mesmo valor.
  - pode criar tendências e enviesar os resultados.

- Preencher os dados em falta com a média, mediana ou moda.
  - pode ser uma boa opção, desde que o desvio padrão não seja grande.
