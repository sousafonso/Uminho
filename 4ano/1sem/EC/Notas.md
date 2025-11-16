# Bases de Dados NoSQL

**Definição de NoSQL**

As bases de dados NoSQL (Not Only SQL) são um tipo de sistema de gestão de bases de dados que **não utilizam a linguagem SQL como principal forma de interação**. Elas foram desenvolvidas para lidar com grandes volumes de dados, alta velocidade de leitura e escrita, e estruturas de dados flexíveis. O NoSQL surgiu precisamente por causa do desafio do Big Data, à medida que empresas como Google, Amazon e Facebook começaram a enfrentar problemas de escalabilidade com as tradicionais bases de dados relacionais.

lembrar bases de dados relacionais...

Uma **base de dados relacional** organiza os dados em tabelas estruturadas com linhas e colunas para representar informações de forma organizada e acessível.

Características principais das bases de dados relacionais:
- Tabelas (relações)
- Chaves primárias e estrangeiras
- Integridade referencial
- Suporte a transações ACID (Atomicidade, Consistência, Isolamento, Durabilidade)

**Atomicidade**: Uma transação deve ter todas as suas operações executadas em caso de sucesso, em caso de falha, nenhum resultado de alguma operação é refletido sobre a base de dados.
**Consistência**: Uma transação deve levar a base de dados de um estado válido para outro estado válido, mantendo todas as regras definidas (como integridade referencial). Uma transação deve respeitar as regras de integridade dos dados (como unidade de chaves, restrições de integridade lógica, etc..).
**Isolamento**: As operações de uma transação devem ser isoladas das operações de outras transações, garantindo que o resultado final seja o mesmo que se as transações fossem executadas sequencialmente. Controlo de concorrência.
**Durabilidade**: Uma vez que uma transação é confirmada, as suas alterações são permanentes e persistem mesmo em caso de falhas do sistema.

## Características das Bases de Dados NoSQL

1. **Escalabilidade Horizontal**: As bases de dados NoSQL podem ser facilmente escaladas adicionando mais servidores ao invés de aumentar a capacidade de um único servidor. Os dados são particionados (sharding) entre vários nós para que cada todo possa executar uma tarefa específica e muitas vezes independente - processo conhecido como "shared nothing architecture".

2. **Modelo de Dados Flexível**: Ao contrário das bases de dados relacionais, que utilizam um esquema fixo, as bases de dados NoSQL permitem que os dados sejam armazenados em formatos variados, como documentos, chave-valor, colunas ou grafos.

3. **Alta Disponibilidade**: Muitas bases de dados NoSQL são projetadas para serem distribuídas, o que significa que os dados são replicados em vários nós, garantindo alta disponibilidade e tolerância a falhas.

4. **Desempenho**: As bases de dados NoSQL são otimizadas para operações de leitura e escrita em grande escala, tornando-as ideais para aplicações que exigem alta performance.

5. **Código aberto**: Muitas bases de dados NoSQL são de código aberto, o que permite uma maior flexibilidade e personalização. 

6. **Sem uma linguagem de consulta padrão**: Diferente do SQL, cada base de dados NoSQL pode ter sua própria linguagem de consulta ou API.

7. **Não seguem os principios ACID**: A maioria das bases de dados NoSQL não seguem os princípios ACID, optando por um modelo de consistência eventual para melhorar a performance e a escalabilidade. Não é rigorosa no cumprimento de restrições de integridade.

Surge o modelo BASE (Basically Available, Soft state, Eventual consistency):
- **Basically Available**: O sistema garante a disponibilidade dos dados, mesmo que algumas partes do sistema estejam indisponíveis. Em vez de impor consistência imediata, garante-se a disponibilidade dos dados ao distribuí-los e replicá-los entre nós do cluster da base de dados.
- **Soft state**: O estado do sistema pode mudar ao longo do tempo, mesmo sem novas entradas, devido à replicação e sincronização dos dados. Os valores dos dados podem mudar ao longo do tempo.
- **Eventual consistency**: Os dados serão eventualmente consistentes, ou seja, todas as réplicas dos dados serão atualizadas em algum momento, mas não necessariamente imediatamente.

## Tipos de Bases de Dados NoSQL

1. **Document Store**: Armazenam dados em documentos (geralmente em formato JSON ou BSON). Exemplos: MongoDB, CouchDB.

2. **Key-Value Store**: Armazenam dados como pares chave-valor. Exemplos: Redis, DynamoDB (Amazon).

3. **Column Family Store**: Armazenam dados em colunas em vez de linhas. Exemplos: Cassandra, HBase.

4. **Graph Database**: Armazenam dados em grafos, permitindo consultas complexas sobre relacionamentos. Exemplos: Neo4j, ArangoDB.

## Quando Usar Bases de Dados NoSQL

As bases de dados NoSQL são particularmente úteis em cenários como:

- Aplicações com grandes volumes de dados não estruturados.
- Sistemas que requerem alta disponibilidade e escalabilidade.
- Projetos que exigem flexibilidade no modelo de dados.

## Modelo Não Relacional

- Depende dos requisitos.
- A situação mais comum ocorre quando os dados são não estruturados ou semi-estruturados.
- O volume de dados (Big Data) pode exigir uma nova maneira de abordar o problema do armazenamento e recuperação de dados.
- A necessidade de escalabilidade horizontal.

## Docker
- Permite criar, implantar e executar aplicações em contêineres.
- Contêineres são unidades leves e portáteis que empacotam uma aplicação e todas as suas dependências, garantindo que a aplicação funcione de forma consistente em diferentes ambientes.

## Document Store Database

**O que é?**
Armazenam dados e derivados em documentos, geralmente em formatos como JSON, BSON ou XML. Cada documento é uma unidade independente que pode conter dados complexos e aninhados.

**Estrutura**
Consistem em dada semi-estruturada, onde cada documento pode ter um esquema diferente. Isso permite uma grande flexibilidade na forma como os dados são armazenados.

**Exemplos**
Exemplo de um ficheiro xml

```xml
<artist>
    <artistname>Iron Maiden</artistname>
    <albums>
        <albumname>The Number of the Beast</albumname>
        <datereleased>1980-04-14</datereleased>
        <genre>Heavy Metal</genre>
    </albums>
    <albums>
        <albumname>Powerslave</albumname>
        <datereleased>1984-09-03</datereleased>
        <genre>Heavy Metal</genre>
    </albums>
```

Exemplo de um ficheiro JSON

```json
{
  "artist": "Iron Maiden",
  "albums": [
    {
      "albumname": "The Number of the Beast",
      "datereleased": "1980-04-14",
      "genre": "Heavy Metal"
    },
    {
      "albumname": "Powerslave",
      "datereleased": "1984-09-03",
      "genre": "Heavy Metal"
    }
  ]
}
```

Transformando isto para tabelas relacionais ficamos com o seguinte:
Tabela Artist:
| artist_id | artist_name  |
|-----------|--------------|
| 1         | Iron Maiden  |

Tabela Album:
| album_id | artist_id | album_name               | date_released | genre       |
|----------|-----------|--------------------------|----------------|-------------|
| 1        | 1         | The Number of the Beast  | 1980-04-14     | Heavy Metal |
| 2        | 1         | Powerslave               | 1984-09-03     | Heavy Metal | 

Tabela de géneros (normalização):
| genre_id | genre       |
|----------|-------------|
| 1        | Heavy Metal |

### Document DB vs RDBMS
| RDBMS                     | Document DB                   |
|--------------------------|-------------------------------|
| Tabelas | Colecções |
| Linhas | Documentos |
| Primary key | \_id (chave única) |
| Foreing key | Documento aninhado ou referência |

Em bases de dados relacionais criamos schemas, em bases de dados de documentos não é necessário. Podemos apenas carregar os dados todos sem usar um schema já pre-definido.

Em bases de dados relacionais temos chaves estrangeiras, em document stores não existem.

As bases de dados de documentos escalam **horizontalmente**. Os dados são transmitidos de forma fácil e com boa performance (**sharding**).
As bases de dados relacionais escalam **verticalmente** (aumentando a capacidade do servidor tanto em memória como em disco).

**Sharding** é o termo que se refere ao processo de dividir um grande conjunto de dados em partes menores e mais gerenciáveis, chamadas shards, que são distribuídas por vários servidores ou nós em um sistema de banco de dados distribuído. Cada shard contém uma parte dos dados totais e pode ser armazenado e gerenciado independentemente dos outros shards.

Tabela resumo:
| Característica          | RDBMS                         | Document DB                   |
|------------------------|-------------------------------|-------------------------------|
| Modelo de Dados        | Estruturado (tabelas)         | Semi-estruturado (documentos)      |
| Esquema                | Fixo                          | Flexível                        |
| Escalabilidade         | Vertical                      | Horizontal                    |
| Transações ACID        | Suportado                     | Limitado (consistência eventual) |
| Linguagem de Consulta   | SQL                           | APIs específicas (ex: MongoDB Query Language) |
| Exemplos               | MySQL, PostgreSQL, Oracle     | MongoDB, CouchDB               |

## Database as a Service (DBaaS)
Database as a Service (DBaaS) é um modelo de serviço em que o provedor de serviços em nuvem gerencia e opera uma base de dados na infraestrutura do cliente. Isso permite que os utilizadores acessem e utilizem a base de dados sem se preocupar com a administração, manutenção ou configuração do hardware e software subjacentes.

Vantagens do DBaaS:
- **Redução da subcarga da gestão**: Os utilizadores não precisam se preocupar com a administração da base de dados, como atualizações, backups e monitoramento.
- **Escalabilidade**: As bases de dados podem ser facilmente escaladas para cima ou para baixo, conforme a demanda.
- **Eficiencia de custo**: Os utilizadores pagam apenas pelo que utilizam, evitando custos fixos elevados (pay as you go).
- **Segurança**: Os provedores de DBaaS geralmente implementam medidas de segurança robustas para proteger os dados dos utilizadores.
- **Soberania dos dados**: Muitos provedores oferecem opções para escolher a localização geográfica dos dados, ajudando a cumprir regulamentos de proteção de dados.
- **Dependencia do fornecedor**: Os utilizadores podem ficar dependentes do provedor de DBaaS para atualizações, suporte e continuidade do serviço. Pode limitar a flexibilidade e migração para outras plataformas.

**Key features**:
- Backups automáticos: Os provedores de DBaaS geralmente oferecem backups automáticos para proteger os dados dos utilizadores.
- Monitoramento e alertas: Ferramentas de monitoramento são frequentemente incluídas para rastrear o desempenho e a saúde da base de dados, com alertas configuráveis para notificar os utilizadores sobre problemas potenciais.
- Segurança integrada: Muitos serviços DBaaS incluem recursos de segurança, como criptografia de dados, controle de acesso baseado em funções e autenticação multifator.

**Use cases**
- Aplicações web e móveis que exigem uma base de dados escalável e gerenciada.
- E-commerce: Plataformas de comércio eletrônico que precisam de bases de dados confiáveis e escaláveis para gerenciar produtos, clientes e transações.
- Big Data e análise: Projetos que envolvem grandes volumes de dados e requerem uma base de dados capaz de lidar com consultas complexas e análises em tempo real.

Exemplos de provedores de DBaaS:
- Amazon RDS (Relational Database Service)
- Google Cloud SQL
- MongoDB Atlas
- Oracle Cloud Database