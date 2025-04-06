# Data Science

**O que é?**
Ciência de dados é um campo multidisciplinar que utiliza métodos, processos, algoritmos e sistemas científicos para extrair conhecimento e insights de dados estruturados e não estruturados.

Data Science é aquilo que está relacionado a recolha, análise, tratamento e tomada de decisão sobre dados.

Ao utilizar Data Science, é possível:
- Determinar o que escolher entre A e B
- Prever o que vai acontecer no futuro
- Identificar padrões em dados

É necessário ter conhecimento em machine learning, estatística, programação, matemática e bases de dados.

Aqui está como um Cientista de Dados trabalha:

**Fazer as perguntas certas** - Para compreender o problema do negócio.  
**Explorar e recolher dados** - De bases de dados, registos web, feedback de clientes, etc.  
**Extrair os dados** - Transformar os dados para um formato padronizado.  
**Limpar os dados** - Remover valores erróneos dos dados.  
**Encontrar e substituir valores em falta** - Verificar valores em falta e substituí-los por um valor adequado (por exemplo, um valor médio).  
**Normalizar os dados** - Escalar os valores para um intervalo prático (por exemplo, 140 cm é menor que 1,8 m. No entanto, o número 140 é maior que 1,8 - por isso, a normalização é importante).  
**Analisar os dados, identificar padrões e fazer previsões futuras.**  
**Representar o resultado** - Apresentar o resultado com insights úteis de uma forma que a "empresa" consiga compreender.

**Data** - conjunto de informações

Os dados podem ser estruturados ou não estruturados.

Podemos usar um array para ou uma tabela para estruturar data:
```python
data = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
```

Construção de um data frame em python:
```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Criar um DataFrame com dados fictícios
data = {
    'Nome': ['Alice', 'Bob', 'Charlie'],
    'Idade': [25, 30, 35],
    'Salário': [50000, 60000, 70000]
}
df = pd.DataFrame(data)
print(df)  
```

O data frame será:
```
      Nome  Idade  Salário
0    Alice     25   50000
1      Bob     30   60000
2  Charlie     35   70000
```

Para consultar o número de colunas/variáveis:
```python
print(df.columns)
```

Para determinar o valor máximo de uma coluna:
```python
print(df['Idade'].max())
```

Para determinar a média de uma coluna:
```python
import numpy as np
print(np.mean(df['Idade']))
```

## Extract and Read Data With Pandas

```python
import pandas as pd

data = pd.read_csv("data.csv", header=0, sep=",")

print(data)
```

É apresentado em forma de tabela.

## NaN rows

Linhas que não têm valor definido.

Podemos usar a função dropna() para remover esses valores não definidos. axis=0 significa que queremos remover todas as linhas que não têm valores definidos. axis=1 significa que queremos remover todas as colunas que têm valores não definidos.
```python
dara.dropna(axis=0,inplace=True)

print(data)
```

## Data Categories
Para analisar dados, também precisamos conhecer os tipos de dados com que estamos a lidar.

Os dados podem ser divididos em duas categorias principais:

**Dados Quantitativos** - Podem ser expressos como um número ou quantificados. Podem ser divididos em duas subcategorias:  
- **Dados Discretos**: Números contados como "inteiros", por exemplo, número de alunos numa turma, número de golos num jogo de futebol.  
- **Dados Contínuos**: Números que podem ter precisão infinita, por exemplo, peso de uma pessoa, tamanho de sapato, temperatura.  

**Dados Qualitativos** - Não podem ser expressos como um número e não podem ser quantificados. Podem ser divididos em duas subcategorias:  
- **Dados Nominais**: Exemplo: género, cor do cabelo, etnia.  
- **Dados Ordinais**: Exemplo: classificações escolares (A, B, C), estatuto económico (baixo, médio, alto).  

Para saber o tipo de dados que temos, podemos usar a função dtypes:
```python
print(data.info())
```

Para converter um tipo de dados para outro, podemos usar a função astype:
```python
data['Idade'] = data['Idade'].astype(int)
```

No lugar de int podemos ter ainda:
- float
- str
- bool
- datetime
- timedelta
- category
- sparse
- object

Para sumarizar os dados, podemos usar a função describe:
```python
print(data.describe())
```
A função **describe()** fornece informações estatísticas sobre os dados, como:
- Count - Counts the number of observations
- Mean - The average value
- Std - Standard deviation (explained in the statistics chapter)
- Min - The lowest value
- 25%, 50% and 75% are percentiles (explained in the statistics chapter)
- Max - The highest value

## Funções lineares
Uma função linear é da forma:
```python
y = mx + b
```

Onde:
- y é o valor que queremos prever
- m é a inclinação da linha
- x é o valor que temos
- b é o valor de y quando x = 0 (intercepto)

Imaginemos o seguinte dataset:
```markdown
| Duration | Average_Pulse | Max_Pulse | Calorie_Burnage | Hours_Work | Hours_Sleep |
|----------|---------------|-----------|-----------------|------------|-------------|
| 30       | 80            | 120       | 240             | 10         | 7           |
| 30       | 85            | 120       | 250             | 10         | 7           |
| 45       | 90            | 130       | 260             | 8          | 7           |
| 45       | 95            | 130       | 270             | 8          | 7           |
| 45       | 100           | 140       | 280             | 0          | 7           |
| 60       | 105           | 140       | 290             | 7          | 8           |
| 60       | 110           | 145       | 300             | 7          | 8           |
| 60       | 115           | 145       | 310             | 8          | 8           |
| 75       | 120           | 150       | 320             | 0          | 8           |
| 75       | 125           | 150       | 330             | 8          | 8           |
```

**Average_Pulse** - Pulsação média
**Max_Pulse** - Pulsação máxima
**Calorie_Burnage** - Calorias queimadas
**Hours_Work** - Horas de trabalho
**Hours_Sleep** - Horas de sono

Imaginemos que queremos apresentar um gráfico com a relação entre a pulsação média e as calorias queimadas. Para isso, podemos usar a biblioteca matplotlib:
```python
import matplotlib.pyplot as plt

health_data.plot(x ='Average_Pulse', y='Calorie_Burnage', kind='line'),
plt.ylim(ymin=0)
plt.xlim(xmin=0)

plt.show()
```

Através do output percebemos que são diretamente proporcionais, no sentido em que podemos usar a pulsação média para **prever** as calorias queimadas.

Em python podemos determinar o declive de uma reta da seguinte forma:
```python
def slope(x1, y1, x2, y2):
  s = (y2-y1)/(x2-x1)
  return s

print (slope(80,240,90,260))
```

Para determinar a interceção de duas retas:
```python
import pandas as pd
import numpy as np

health_data = pd.read_csv("data.csv", header=0, sep=",")

x = health_data["Average_Pulse"]
y = health_data["Calorie_Burnage"]
slope_intercept = np.polyfit(x,y,1)

print(slope_intercept)
```
O resultado será um array com dois valores, o primeiro é o declive e o segundo é a interceção.

Em **polyfit**:
- O primeiro argumento é o eixo x
- O segundo argumento é o eixo y
- O terceiro argumento é o grau do polinómio (1 para uma reta, 2 para uma parábola, etc.)

Para definição das janelas de plotagem:
```python
import matplotlib.pyplot as plt

health_data.plot(x ='Average_Pulse', y='Calorie_Burnage', kind='line'),
plt.ylim(ymin=0, ymax=400)
plt.xlim(xmin=0, xmax=150)

plt.show()
```

## Percentis

Os percentis são valores que dividem um conjunto de dados em 100 partes iguais. Por exemplo, o percentil 50 (também conhecido como mediana) é o valor que divide os dados em duas metades, onde 50% dos dados estão abaixo desse valor e 50% estão acima.
Os percentis são úteis para entender a distribuição dos dados e identificar valores extremos ou outliers. Por exemplo, se um aluno obteve uma nota no percentil 90 em um teste, isso significa que ele teve um desempenho melhor do que 90% dos outros alunos.

Analisando o dataset anterior, 
Vamos tentar explicar com alguns exemplos, usando a pulsação média (Average_Pulse).

- O percentil de 25% da pulsação média significa que 25% de todas as sessões de treino têm uma pulsação média de 100 batimentos por minuto ou menos. Se invertermos a afirmação, significa que 75% de todas as sessões de treino têm uma pulsação média de 100 batimentos por minuto ou mais.
- O percentil de 75% da pulsação média significa que 75% de todas as sessões de treino têm uma pulsação média de 111 batimentos por minuto ou menos. Se invertermos a afirmação, significa que 25% de todas as sessões de treino têm uma pulsação média de 111 batimentos por minuto ou mais.


Exemplo de aplicação em python:
```python
import numpy as np

Max_Pulse= full_health_data["Max_Pulse"]
percentile10 = np.percentile(Max_Pulse, 10)
print(percentile10)
```

O resultado será o valor do percentil 10 da pulsação máxima.

**Output:**
120.0

### Standard Deviation
A desvio padrão é uma medida estatística que indica a quantidade de variação ou dispersão num conjunto de dados. Em outras palavras, ele mostra o quanto os valores individuais num conjunto de dados diferem da média desse conjunto.

Em python:
```python
import numpy as np

std = np.std(full_health_data)
print(std)
```
O resultado será o desvio padrão de todos os dados.

O **coeficiente de variação** é uma medida estatística que expressa a relação entre o desvio padrão e a média de um conjunto de dados. Ele é útil para comparar a variabilidade de diferentes conjuntos de dados, mesmo que tenham unidades ou escalas diferentes. Ele permite saber o quão grande é a variação.

O coeficiente de variação é calculado como:
```python
import numpy as np

cv = np.std(full_health_data) / np.mean(full_health_data)
print(cv)
```

### Variância
A variância é uma medida estatística que indica a quantidade de variação ou dispersão num conjunto de dados. Ela é calculada como a média dos quadrados das diferenças entre cada valor e a média do conjunto.

Em python:
```python
import numpy as np

var = np.var(health_data)
print(var)
```