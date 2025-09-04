# Artificial Intelligence
A inteligência artificial também pode ser chamada de Machine Intelligence e Computer Intelligence.

É uma disciplina científica composta por diversos subconjuntos de Data Science que vão desde narrow AI (weak AI) até strong AI, incluindo machine learning, deep learning, big data e data mining.

**Narrow AI** é limitada a áreas específicas como:
- Google Maps
- Deteção facial
- Siri
- Algoritmos de procura

Weak AI: Criada para simular inteligência humana
Strong AI: Criada para copiar a inteligência humana. Ou seja, transmite a ideia de pensamento, planeamento, aprendizagem, comunicação e consciência.

Linguagens de programação que permitem usar IA são:
- LISP
- R
- Python
- C++
- Java
- JavaScript (atualmente a mais versátil e eficaz)
- SQL

---

## Machine Learning
Machine Learning (ML) é um subdomínio da Inteligência Artificial (IA) que se concentra no **desenvolvimento de algoritmos e modelos que permitem que os computadores aprendam a partir de dados**. O objetivo do ML é capacitar os sistemas a melhorar seu desempenho em tarefas específicas com base na experiência, sem serem explicitamente programados para cada tarefa.

Programas tradicionais utilizam algoritmos para produzirem resultados sobre dados:
```math
Data + Algorithms = Results
```

Machine Learning cria algoritmos através de dados e resultados:
```math
Data + Results = Algorithms 
```

Machine Learning usa relações entre inputs e predictions.

Normalmente em algebra uma relação é da forma:
```math
y = mx + b
```
onde,
- y é a variável que queremos prever (label)
- m é o declive
- x são os valores de input
- b é a interseção

Em machine learning, essa relação é da forma:

```math
y = b + wx
```

onde,
- y é a variável que queremos prever (label)
- w é o peso (declive na mesma)
- x são as features (input)
- b é a interseção

Por vezes podemos ter mais do que uma feature (input values) com diferentes pesos cada uma:

```math
y = b + w_1x_1 + w_2x_2 + w_3x_3 + ... + w_nx_n
```

Ciclo de vida de um modelo:
1. Data Collection
2. Training
3. Inference (values prediction)

### Aprendizagem
Existem alguns tipos de aprendizagem

#### 1. Supervisionada
A partir de variáveis de input, o modelo consegue prever o output de uma outra variável. Ou seja, o algoritmo aprende a partir de exemplos com respostas conhecidas. Dás ao modelo dados de entrada + a saída correta, e ele aprende a prever saídas para novos dados.

#### 2. Não supervisionada
Aqui os dados não têm respostas conhecidas. O algoritmo tem de descobrir padrões ou grupos por si só

Problemas típicos:
- **Clustering (Agrupamento)**: encontrar grupos de dados semelhantes (Ex.: clientes com perfis de consumo parecidos)
- **Redução de dimensionalidade**: simplificar dados complexos mantendo a informação principal.

#### 3. Reforço
Estilo semelhante à não supervisionada só que aqui o modelo é avaliado de acordo com o feedback do utilizador evoluindo naturalmente.

---
## Clustering
Clusters são coleções de dados baseados em similiaridade.
Exemplos de clusters:

Methods:
- **Density Method**: são considerados pontos numa área mais densa onde implica maior similiaridade. Exemplos de algoritmos.: DBSCAN e OPTICS.
- **Hierarchical Method**: Novos grupos são formados a partir de grupos anteriormente formados. Exemplos de algoritmos.: CURE e BIRCH;
- **Grid-based Method**: os dados são dividos em células formando uma espécie de tabela. Exemplos de algoritmos.: CLIQUE e STING;
- **Partitioning Method**: divide os objetos em k grupos;

<p style="color: lightblue;"> Coeficiente de Correlação</p>
Descreve a força e a direção de uma relação linear. O valor varia de -1 a 1 da seguinte forma:

|Correlação   |Descrição  |Implicação
| :--------------   |:------------  |:------------
| -1                  |Perfect Downhill               |Relação negativa linear
| -0.7   |Strong Downhill  | Relação negativa linear
| -0.5   |Moderate Downhill  | Relação negativa linear
|-0.3 | Weak Downhill | Relação negativa linear
| 0| | Sem correlação
| 1                  |Perfect Uphill               |Relação positiva linear
| 0.7   |Strong Uphill  | Relação positiva linear
| 0.5   |Moderate Uphill  | Relação positiva linear
|0.3 | Weak Uphill | Relação positiva linear

---
## Regressões
Método para determinar a relação entre uma variável y e várias variáveis x.


---
## Redes Neuronais
Redes Neurais são modelos computacionais inspirados no funcionamento do cérebro humano, compostos por camadas de nós (**neurônios**) que processam informações. Elas são amplamente utilizadas em tarefas de reconhecimento de padrões (reconhecimento facial), como classificação de imagens, processamento de linguagem natural e jogos.
As redes neurais são **treinadas ajustando os pesos das conexões entre os neurônios** para minimizar a diferença entre as previsões do modelo e os resultados reais. Esse processo é conhecido como **aprendizagem supervisionada**, onde o modelo é alimentado com um conjunto de dados rotulados (entrada e saída) para aprender a mapear entradas para saídas corretas. **É um tipo de software que aprende com os erros. Conexões mais fortes levam a resultados mais fortes.**

### Perceptron
O Perceptron é o modelo mais simples de rede neural, composto por **uma única camada de neurônios**. Ele é usado para tarefas de classificação binária, onde a saída é uma decisão entre duas classes (por exemplo 0 ou 1). O Perceptron recebe **entradas**, aplica **pesos** a essas entradas, **soma os resultados** e passa por uma **função de ativação para produzir a saída**. Existindo um threshold para sabermos atribuirmos um valor 0 ou 1. O treino do Perceptron **envolve ajustar os pesos com base no erro entre a saída prevista e a saída real**, usando o algoritmo de retropropagação (backpropagation algorithm).

**Training**
Precisamos de 2 parâmetros:
- número de inputs
- learning rate (usada para ajudar os pesos aquando da presença de erros)

As vezes quando o input é o mesmo, por exemplo 0 e 0, o perceptron pode produzir um output incorreto, daí surge a necessidade de adotar um bias.

**Testing**
Para testar o nosso perceptron podemos calcular o número de erros.

**Learning**
O modelo é treinado através de vários loops, onde em cada loop, os pesos sofrem ajustes. O treino fica completo quando o teste da redução de custo (função de custo) falha.

> **Gradiente Descendente**:
Algoritmo popular em IA. Uma função linear de regressão pode ser usado para demonstrar o gradiente descendente. Inicialmente é adotada um modelo linear de equação y = ax + b. Depois o modelo é treinado de modo a enquadrar-se com os dados e este enquadramento é feito alternando os pesos (a - declive) e o bias (b - interceção com as ordenadas).

Deve ser criado um objeto de treino com uma constante de aprendizagem, definir os pesos a 0, o bias a 1 e um custo:

```JavaScript
function Trainer (xArray, yArray){
    this.xArr = xArray;
    this.yArr = yArray;
    this.points = this.xArr.length;
    this.learnc = 0.00001;
    this.weight = 0;
    this.bias = 1;
    this.cost;
}
```

A função de custo é definida da seguinte forma:
```JavaScript
this.costError = function(){
    total = 0;
    for (let i = 0; i < this.points; i++){
        total += (this.yArr[i] - (this.weight * this.xArr[i] + this.bias)) **2;
    }
    return total / this.points;
}
```

A função de treino que vai executar o gradiente descendente obtendo a melhor equação de ajuste aos pontos do gráfico é definida da seguinte forma:
```JavaScript
this.train = function(iter){
    for(let i = 0; i < iter; i++){
        this.updateWeights();
    }
    this.cost = this.costError();
}

this.updateWeights = function(){
    let wx;
    let w_deriv = 0;
    let b_deriv = 0;
    for (let i = 0; i < this.points; i++){
        wx = this.yArr[i] - (this.weight * this.xArr[i] + this.bias);
        w_deriv += -2*wx*this.xArra[i];
        b_deriv += -2*wx;
    }
    this.weight -= (w_deriv / this.points) * this.learnc;
    this.bias -= (b_deriv / this.points) * this.learnc;
}
```

A função que atualiza os pesos e o bias utiliza duas derivadas parciais para determinar a direção que a linha deve tomar.

### Multi-Layer Perceptrons
input layer + hidden layer + output layer

- Input Layer
Decisões simples são tomadas consoante o input. Cada decisão tomada é passada para a camada seguinte

- Hidden Layer
Aqui os perceptrons tomam decisões atribuindo um peso aos resultados recebidos pela camada anterior. Aqui as decisões são mais complexas e têm um nível mais abstrato.

### Deep Neural Networks
A diferença para o anterior é que aqui podemos ter mais do que uma hidden layer antes da output layer.

### Brain.js
Biblioteca do JavaScript para uso de redes neuronais sem complexidade matemática.
```JavaScript
const network = new brain.NeuralNetwork();

// train the network com 4 input objects
network.train([
    {input:[0,0], output:[zero:1]},
    {input:[0,1], output:[one:1]},
    {input:[1,0], output:[one:1]},
    {input:[1,1], output:[zero:1]},
])

// qual é o output de [1,0]?
result = network.run([1,0]);
```

---
## Deep Learning
Deep Learning é um subconjunto de machine learning. É também responsável pelo AI boom nos últimos anos. Mas é um tipo muito avançado de ML que é capaz de reconhecer imagens.

|Machine Learning   |Deep Learning  |
| :--------------   |:------------  |
| Um subconjunto de IA                  |Um subconjunto de machine learning               |
| Usa um tamanho de dados mais reduzido   |Usa um tamanho de dados elevado  |
| Treinada por humanos   |Aprende sozinha  |
|Cria algoritmos simples | Cria algoritmos completos

---


## Vocabulário
<div style="display:flex; gap: 20px">
    <div style = "flex: 1;">
        <li>
            População: grupo de indivíduos (objetos) que queremos recolher informação de;
        </li>
        <li>
            Sample: informação sobre uma porção de uma população de modo a representar o todo;
        </li>
        <li>
            Censo: informação de todo o objeto de uma população;
        </li>
        <li>
            Big Data: Data que se torna impossível para qualquer humano processar. Apenas com auxílio de uma máquina.
        </li>
        <li>
        
        </li>
    </div>
    <div style = "flex: 1;">
        <li>
            Sample bias: quando indivíduos são mais ou menos propicios para entrar na amostra;
        </li>
        <li>

        </li>
        <li>
        
        </li>
    </div>
</div>

          