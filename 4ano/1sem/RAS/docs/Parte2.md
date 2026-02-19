# 📘 SÍNTESE INTEGRADA COMPLETA - PARTE II
## Elicitação, Modelação e Arquitetura Fundamental

**Documento Complementar a Parte I**  
**Data:** 17 de Janeiro de 2026  
**Cobertura:** RAS-5, RAS-6, RAS-7, RAS-8  

---

# PARTE II: TÉCNICAS, MODELAÇÃO E ARQUITETURA

## 4. ELICITAÇÃO DE REQUISITOS: TÉCNICAS E STAKEHOLDERS

### 4.1 Processo de Elicitação

**Escopo**: Elicitação permite compreender **quais são os requisitos** de um sistema determinado.

Designações alternativas: Requirements discovery, capture, recollection, acquisition, extraction, crawling.

**Objetivo**: Compreender necessidades e expectativas que stakeholders têm em relação ao sistema.

**Natureza**: Atividades **comunicacionais**, envolvendo técnicas de ciências sociais e teoria organizacional.

**Duas Fases Principais**:

1. **Contact persons** que conhecem bem o problema
   - Identificar todas restrições que poderiam limitar solução
   - Caracterizada por uncertainty e aumento de informação/conhecimento

2. **Prepare requirements document**
   - Descrever comportamento e características esperadas
   - Caracterizada por organização de ideias, resolução de conflitos, eliminação de inconsistências

### 4.2 Identificação de Stakeholders

#### 4.2.1 Definição de Stakeholder

**Stakeholder**: Pessoa materialmente afetada pela implementação do sistema.

OU

**Stakeholder**: Pessoa com algum tipo de interesse legítimo no sistema.

Termo "pessoa" deve ser entendido em sentido amplo: grupos de pessoas, organizações.

O "interesse" é também amplo: resultar de utilização, ser afetado, ou ter responsabilidade em relação ao sistema.

#### 4.2.2 Tipos de Stakeholders (6 Categorias)

##### **User** (Utilizador)

- Pessoa que **opera e interage diretamente** com sistema
- Quando sistema está em operação efetiva no seu ambiente
- **Pessoas na frente do ecrã** para introduzir dados ou observar resultados
- Exemplo: Driver e passengers de carro são ambos users (mas responsabilidades distintas)
- **Recomendação**: Preferência para users que mais frequentemente interagem com sistema

**Particularidades a Considerar**:
- Pessoas com deficiências (visual, motora, cognitiva)
- Pessoas com baixa literacia
- Pessoas que não dominam línguas do sistema
- Pessoas com dificuldades visuais (óculos, daltónico, cego)
- Pessoas transportando/manipulando substâncias
- Pessoas com destreza reduzida

##### **Client** (Cliente)

- Entidade que **ordena e paga** pelo desenvolvimento
- Relação formalizada via contrato
- **Poder de decisão** sobre: scope, funcionalidades, custo
- Responsável por fornecer documentação técnica completa ao cliente (para instalação/manutenção)
- **Clientes frequentemente não são utilizadores do sistema**

##### **Customer** (Cliente Final/Consumidor)

- Pessoa que **adquire e usa** o sistema
- **Consumidor final** para quem sistema é renderizado
- Em muitos casos, nomes de clientes são conhecidos antes desenvolvimento
- Para produtos mass-market: clientes são pessoas que adquirem quando disponível
- Acto de compra não necessariamente envolve transação financeira

**Citação Famosa** (Henry Ford):
> "It is not the employer who pays the wages, but the customer."

**Citação Moderna** (Ron Kohavi, Microsoft):
> "Listen to your customers, not to the HiPPO"
> (HiPPO = Highest Paid Persons Opinion)

##### **Market Segment** (Segmento de Mercado)

Caracterização de necessidades e comportamentos comuns de clientes:

Um grupo de clientes representa distinct market segment se:
1. Necessidades demandam e justificam offer diferente
2. Abordados através de canais distribução distintos
3. Necessitam de tipos relações diferentes
4. Têm significativamente níveis profitabilidade distintos
5. Estão dispostos a pagar por aspetos diferentes da offer

##### **Negative Stakeholder** (Stakeholder Negativo)

Pessoa que **deseja que sistema NÃO seja desenvolvido**.

Atitude pode variar: Oposição pacífica a hostilidade ativa.

Identificação permite:
- Identificar tentativas de sabotagem
- Compreender relações pessoais e políticas na organização
- Sua presença em elicitação é **relevante**

**Número de Stakeholders**: Tipicamente **alto** (frequentemente 6+).

#### 4.2.3 Formas de Identificar Stakeholders

1. Perguntar ao cliente
2. Examinar organigrama da organização
3. Comparar com produtos similares
4. Analisar contexto do sistema
5. Consultar stakeholders comuns na maioria dos sistemas

### 4.3 Técnicas de Elicitação (11 Técnicas)

#### 4.3.1 Competências Genéricas

Engenheiro de requisitos deve dominar: **Questioning, Observing, Discussing, Negotiating, Supposing**

#### 4.3.2 Técnicas para Indivíduos

##### **INTERVIEW** (Entrevista)

- Entrevistador tem **grande liberdade**
- Conversas completamente abertas frequentemente produzem resultados pobres
- **Deve ser estruturada**

**Processo** (4 fases):
1. **Identify interviewees** - Selecionar pessoas
2. **Prepare interview** - Planear questões
3. **Conduct interview** - Realizar
4. **Conclude interview** - Finalizar

**Identificação de Entrevistados**:
- Entrevistar **cliente e alguns utilizadores**
- Para produto: sample representativa da comunidade
- Pode ser iterativa: "Quem mais devo entrevistar?"

**Recomendações**:
- Explicar contexto, objectivos, duração
- Usar case diagrams como referência
- Usar modelos/figuras para encorajar modificações
- Usar terminologia do problema, evitar jargão de solução

##### **SURVEY** (Sondagem)

- Técnica usando **questionário** para recolher informação de múltiplos respondentes
- Comum na elicitação inicial de requisitos

**Processo** (5 fases):
1. Identify audience
2. Conceive questionnaire
3. Determine sample
4. Recruit participants
5. Conduct survey

**Questão** = Conjunto de questões para recolher informação.

Quando mesmo questionário usado para todas pessoas: possível **processar estatisticamente** respostas.

**Sucesso depende de**: Como questionnaire é concebido.

Construir questionnaire poderoso e relevante **não é fácil**.

Se questões não focadas, mal formuladas, ou em ordem errada: respostas podem ser enganosas.

**Recomendações**:
- Evitar questões negativas (difícil de responder)
- Questionnaires frequentemente não totalmente respondidos, respostas mal elaboradas
- Computer-based tools podem lidar com missing answers
- Survey deve ser técnica preliminar preparando interviews

##### **INTROSPECTION** (Introspecção)

- **Mais básica, óbvia e rudimentar** de todas técnicas

Analista define requisitos baseado no **que pensa serem necessidades** dos stakeholders.

Engenheiro **coloca-se no papel** do cliente/utilizadores.

Raciocina baseado em premissas: "If I were the client, I would like the product to..."

**Uso**: Extensivamente usado quando engenheiros têm **deep knowledge** do domínio.

**Limitação**: Pode ser usado apenas como **starting point**, necessitando outras técnicas depois.

##### **DOMAIN ANALYSIS** (Análise de Domínio)

Analisar documentação e estudar sistemas existentes = boa fonte de requisitos.

Pressupostos:
- Analisar sistemas upstream e downstream
- Examinar sistemas com propósitos similares

Objetivo: Examinar **domínio onde sistema localizado**, para identificar **elementos comuns de todos sistemas** no domínio.

**Análise de documentos**: Técnica baseada em procurar requisitos em documentos, relatórios, manuais.

Possível em futuro se artefatos de projetos actuais forem armazenados.

#### 4.3.3 Técnicas de Grupo

##### **BRAINSTORMING** (Geração de Ideias)

- Facilita **geração de ideias**
- Sessão congrega grupo de **5 a 12 pessoas**
- Grupo sugere e explora **tantas ideias quanto possível**
- **Sem criticar ou julgar** ideias

**Processo** (2 fases):
1. Generate ideas
2. Consolidate ideas

##### **GROUP DYNAMICS & COOPERATIVE WORK**

Envolvem dinâmica de grupos e trabalho cooperativo dos stakeholders.

#### 4.3.4 Técnicas de Artefatos

##### **PROTOTYPING** (Prototipagem)

Cliente pode definir apenas objectivos genéricos, sem detalhe funcionamento.

Abordagem baseada em prototypes pode ser mais adequada.

**Pressupostos**: Processo iterativo.

**Processo** (3 fases):
1. Elicit requirements
2. Construct prototype
3. Test prototype

Prototype serve **apenas como mecanismo para capturar requisitos**.

Uma vez requirements do cliente claramente compreendidos, **prototype é abandonado**.

**Não é construir produto final.**

##### **PERSONA** (Persona)

Técnica comum em advertising, ganhou popularidade recentemente em requirements engineering.

**Persona** = Pessoa fictícia que representa **tipo importante de utilizadores** do produto.

Persona é **arquétipo** das pessoas parte da target audience.

Deve ser concebida para **representar essas pessoas no que é essencial e distintivo**.

Técnica de **segmentação de mercado**.

**Exemplo de Persona**:
```
Susan Taylor, always-connected bank clerk
Age: 28 anos
Civil State: Single
Qualifications: Graduated Economics
Profession: Bank clerk
Salary: EUR 1.500/month
Residence: 1-room house, Slough, 32 km west London

Lifestyle: Gosta sair noites com amigas, cinema, shopping
         Adora comprar sapatos (100+ pares)
         Procura boyfriend para relação séria
         Quer ser mãe antes dos 32 anos

Context: Addicted smartphone, email, social networks
        Aplicações para latest songs
        Adora concerts, summer festivals

Objectives:
1. Be informed about concerts with appreciated artists
2. Forward info to friends via social networks
3. Receive suggestions about songs based on tastes
```

**Processo** (5 fases):
1. Identify problem
2. Create personas
3. Introduce personas
4. Use personas
5. Evaluate personas

---

## 5. MODELAÇÃO DE REQUISITOS COM UML

### 5.1 Conceitos Fundamentais de Modelação

**Modelação**: Processo de identificar **conceitos adequados** e **selecionar abstrações** para construir modelo que **apropriadamente reflete** um dado universo de discurso.

**Propósito**: Permitir uso cost-effective do **modelo em lugar do objeto/processo real**.

Modelação relaciona-se com: **Abstraction, Simplification, Formalisation**.

**Abstração**: Ideia de **remover tudo não essencial** para fazer um ponto.

### 5.2 Características de Modelos (5 Propriedades)

1. **Abstraction**: Descrição reduzida do sistema
2. **Understandability**: Remover detalhes irrelevantes permite compreensão mais fácil
3. **Accuracy**: Para propriedades de interesse, modelo fornece representação verdadeira do sistema
4. **Reasoning**: Modelo ajuda análise e raciocínio correto sobre propriedades não-óbvias (via experimentação/simulação ou análise formal)
5. **Inexpensiveness**: Modelo deve ser drasticamente mais barato construir e analisar que sistema

### 5.3 Dimensões de Modelos (3)

| Dimensão | Opção 1 | Opção 2 |
|----------|---------|---------|
| **Form** | Physical (Iconic) - Materializado, reprodução reduzida | Symbolic (Mathematical) - Relações lógicas/quantitativas |
| **Representativeness** | Prescriptive - Como deve ser (forward engineering) | Descriptive - Como é (reverse engineering) |
| **Perspective** | Structural - Estático, componentes/módulos | Behavioural - Dinâmico, comportamento |

### 5.4 Seis Diagramas UML Essenciais para Requisitos

#### 5.4.1 DOMAIN MODEL

**Propósito**: Descrever **vocabulário, conceitos do domínio** e características dos sistemas que podem ser desenvolvidos para esse domínio.

**Inclui**:
1. Definição scope do domínio (exemplos, regras inclusão)
2. Vocabulário do domínio (glossário com termos principais)
3. Modelo conceitos (identifica e relaciona conceitos do domínio)

**Exprime**: Enduring truths sobre universo relevante ao sistema.

**Exemplo (Tic-Tac-Toe)**:
```
Square (state: Marked X, Marked O, Empty)
Board (composed of 9 Squares, 1:9)
Player (X Player, O Player)
Tic-tac-toe (played by 2 Players, has 1 Board)
```

#### 5.4.2 USE CASE MODEL

**Propósitos**:
1. Definir **frontier do sistema** com o ambiente
2. Especificar **funcionalidades** que sistema disponibiliza aos utilizadores

**Elementos Básicos**:
- **Use case** (funcionalidade)
- **Actor** (utilizador/papel externo)
- **System boundary** (limite do sistema)

**Guias**:
- Usar verbos para caracterizar use cases (realça natureza funcional)
- Use cases **não modelam workflows/processos**
- Muitos small use cases com mesmo objectivo podem ser agrupados
- **Passos de use case não são use cases separados** (não é decomposição funcional)

#### 5.4.3 CLASS MODEL

**Propósito**: Indicar classes existentes e suas relações.

**Elementos**:
- Class (name, attributes, operations)
- Relations:
  - **Association** (relação genérica)
  - **Aggregation** (todo-parte, não exclusivo)
  - **Composition** (todo-parte, exclusivo)
  - **Generalization/Specialization** (herança)
- **Multiplicity** (quantas instâncias)
- **Navigation** (direcção)
- **Role** (papel na relação)

#### 5.4.4 SEQUENCE MODEL

**Propósito**: Modelar **aspetos dinâmicos** - troca de mensagens entre objectos.

**Uso**: Representar **instance de um use case**.

Descreve como **grupo de objectos comunicam**, enfatizando **fluxo de controlo e dados**.

**Elementos**:
- Object lifelines (objectos participantes)
- Messages (msg1, msg2, etc.)
- Events (ev1, ev2, etc.)
- States (Stt1, Stt2, etc.)
- Timing marks

#### 5.4.5 STATE MODEL

**Propósito**: Definir **comportamento dinâmico/temporal** de uma classe.

Classe models não permite **comportamento dinâmico** das instâncias.

State diagrams definem como **classe transita entre estados**.

**Definição**: **Estado** = Condição ontológica que persiste período significativo, distinguível e disjunta de outras.

**Elementos**:
- States (Stt1, Stt2, etc.)
- Transitions (t1, t2, etc.)
- Guards (condições)
- Entry/Exit actions
- Superstates (nested)
- History connectors

**Exemplo (Pessoa)**:
```
single → marry → married
married → divorce → divorced
single → get married → married
spouse die → widower
```

#### 5.4.6 ACTIVITY MODEL

**Propósito**: Relacionar **fluxo de controlo** entre actividades de dado processo business.

Enderaço **aspetos comportamentais** de sistemas/entidades.

Apropriado quando **comportamento muda principalmente devido fim de acção/actividade**.

**Elementos**:
- Activities
- Decision points (else/ok)
- Start/End
- Swim lanes (departamentos/responsáveis)
- Junctions/Merges

---

## 6. DOCUMENTAÇÃO DE REQUISITOS EM LINGUAGEM NATURAL

### 6.1 Template Genérico (27 Secções)

Uma estrutura pré-definida para documentos de requisitos é **importante**, pois:
- Grande diversidade de projetos de engenharia
- Sem template: graus de liberdade excessivos, documentos muito diferentes
- **Estrutura pré-definida especialmente útil para sistemas complexos**

**Template Genérico (27 Secções)**:

**Project Triggers** (5-6):
1. Purpose of system
2. Client, customer, stakeholders
3. Users of the system

**Project Restrictions** (4-9):
4. Mandatory restrictions
5. Taxonomy and definitions
6. (Additional)

**Functional Requirements** (7-9):
7. Scope of work
8. Scope of system
9. Functional & data requirements

**Non-Functional Requirements** (10-17):
10. Appearance
11. Usability
12. Performance
13. Operational
14. Maintenance & Support
15. Security
16. Cultural & Political
17. Legal

**Project Issues** (18-27):
18. Open issues
19. Immediate solutions
20. New problems
21. Tasks
22. Migration to new system
23. Risks
24. Costs
25. User manual
26. Waiting room
27. Ideas for solutions

### 6.2 Guidelines para Escrita Técnica

**Princípios Fundamentais**:

Escrever requisitos em linguagem natural é **inevitável**.

Não é expectável que todos stakeholders interpretem especificações formais.

Engenheiros devem saber **comunicar com qualquer pessoa comum**.

**Writing em forma eficaz é task propensa a erros.**

Requisitos segundo **conjunto de princípios e recomendações** são importantes.

**Escrever requisitos requer continuous enhancement via training e prática.**

### 6.3 Regras de Escrita Técnica

1. **Linguagem simples, clara, precisa**
2. **Sem figuras de linguagem** (metaphors, similes)
3. Palavras em **significados denotativos**, sem espaço para interpretações alternativas
4. **Impessoal, objectivo, modesto, educado**

### 6.4 Formatos Padronizados

#### **User Requirements**:
```
[Subject: user type] [Predicate: verb/functionality]
[Object: what is achieved] [Test: how to verify]

Exemplo: "The hotel receptionist shall visualise the room
number of a guest within 2 seconds after making request"
```

#### **User Stories** (Agile):
```
As a [user type], I want [objective] for [reason]

Exemplo: "As a hotel receptionist, I want to visualise
the room number of a guest for calling him if someone
wants to contact him"
```

Coloca utilizador como **foco de atenção**, facilita identificação de sources.

#### **System Requirements**:
```
[Subject: system entity] [Predicate: verb/functionality]
[Object: what is achieved] [Description: details]

Exemplo: "The battery signal shall turn on when the
charge is lower than 20 mAh"
```

#### **Non-Functional Requirements**:
```
[System] [Quality to achieve] [verb: be/have]
[Description]

Exemplos:
- "The product shall be easy to use for illiterate persons"
- "The product must continue to function at 30 metres underwater"
- "The product must be prepared to be translated to any language"
- "The source code of product programs should contain comments"
```

### 6.5 Questões a Evitar (6)

#### **1. AMBIGUITY** (Ambigüidade)

Característica de palavras/expressões/sentenças que expressam **mais que uma interpretação possível**.

Amplamente usado em poetry, publicity, jokes - **deve ser proibido em textos técnicos**.

**Tipos**:

**Homonymy**: Duas ou mais distintas, não-relacionadas meanings compartilham mesma forma lexical.
```
"The secretary of the director is tall"
"The secretary of the director is unsympathetic"
(Qual secretary? De qual director?)
```

**Polysemy**: Mesma unidade lexical suporta duas ou mais meanings semanticamente relacionadas.

**Possessive Pronouns**: Ambigüidade da 3ª pessoa singular/plural após múltiplos subjects.
```
"The director called the doctor about his problems"
(His = director ou doctor?)
```

**Conjunctions**: Problemas interpretação após enumeração.
```
"The managers inform the directors and the secretaries,
because they are responsible for editing the document"
(Who is responsible? Managers? Directors? Secretaries? Both?)

Solução: "The managers inform the directors and the
secretaries, because the latter are responsible..."
```

**And vs Or**: Em linguagem comum, frequ términentemente têm efeitos idênticos. Uso deve ser bem analisado.

Em matemática: AND ≠ OR (Boolean operators). Mas "and/or" é fonte de ambigüidade - prefira "or".

#### **2. VAGUE TERMINOLOGY** (Terminologia Vaga)

Muitas palavras informais para indicar características desejáveis são **demasiado vagas**:
- Easy to use/learn
- Versatile, Flexible
- Intuitive, Modern
- Improved, Efficient
- Approximately, More possible, Minimal impact

**Solução**: Complementar escrita do requisito com **definição de critérios verificáveis**.

Exemplo:
```
RUIM: "The e-mail application must have an intuitive user interface"

BOM: "The interface is intuitive if, on first utilisation without help,
85% of users are able to perform most basic tasks within 25 minutes"
```

#### **3. ILLUSIONS & FANTASIES** (Ilusões e Fantasias)

Em engenharia, **não existem componentes perfeitos**.

Evitar **wishful thinking** de alcançar o impossível.

Equipas devem ter **atitude realista**, rejeitando requisitos com ideias ilusórias ou irrealistas.

**Evitar**: "100% reliable", "totally safe", "never fails", "satisfies all users", "handles all unforeseen situations"

#### **4. MULTIPLE REQUIREMENTS** (Múltiplos Requisitos)

Requisitos com **coordinating conjunctions** são especialmente susceptíveis a ambigüidade.

**Evitar**: FANBOYS (for, and, nor, but, or, yet, so)

**Solução**: Dividir em requisitos simples.

#### **5. DESIGN** (Especificação de Design)

Evitar indicar **COMO o sistema satisfará** requisito (muito detalhe, pre-design decisions).

Perder oportunidade de considerar **soluções técnicas mais adequadas**.

Foco deve estar nas **funcionalidades** que sistema fornecerá aos utilizadores.

**Evitar referências a**:
- Component names
- Materials
- Database fields
- Technological aspects

#### **6. PROJECT PLANS** (Planos de Projeto)

Planos de projeto e scheduling **não devem estar em documento requisitos**.

**Evitar**: Datas, phases, atividades de projeto.

Essa informação deve estar em **documento separado: project plan**.

---

## 7. FUNDAMENTOS DE ARQUITETURA DE SOFTWARE

### 7.1 Definição de Software Architecture

**Definição 1** (Clements et al., 2010):
> "The set of structures needed to reason about the system, which comprise software elements, relations among them, and properties of both"

**Definição 2** (ANSI/IEEE Std 1471-2000):
> "The fundamental organization of a system, embodied in its components, their relationships to each other and the environment, and the principles governing its design and evolution"

### 7.2 Estruturas Static vs Dynamic

**Static Structures**: Definem **design-time elements** do sistema e seu arranjo.

**Dynamic Structures**: Definem **run-time elements** do sistema e suas interações.

### 7.3 Relação: Functional Requirements vs Architecture

**Facto Crítico**: Dois arquitetos dados **mesmos requisitos**, frequentemente produzem **diferentes arquiteturas**.

**Implicação**: Functional requirements **não determinam arquitetura**.

Arquitetura é realização de **early design decisions** para decompor sistema em partes.

### 7.4 Fatores que Influenciam Arquitetura

1. **Stakeholders** (necessidades, poder)
2. **Developing organization** (capacidades, processos)
3. **Background & experience of architects**
4. **Technical environment** (plataforma, ferramentas)

**Facto**: Uma arquitetura **afecta os fatores que a influenciam**. Bidirectional relationship.

### 7.5 Design Principles Fundamentais

**Princípios de Design** = Leis/doutrinas/pressupostos comprehensive e fundamentais.

**Princípios Key**:
1. **Abstraction** - Conceitos essenciais apenas
2. **Coupling & Cohesion** - Minimizar dependências, maximizar coesão interna
3. **Decomposition & Modularization** - Dividir em partes geríveis
4. **Encapsulation & Information Hiding** - Esconder implementação
5. **Separation of Interface & Implementation**
6. **Separation of Concerns** - Cada módulo responsável por uma coisa
7. **Sufficiency, Completeness, Primitiveness**

### 7.6 Architecture vs Functionality

**Facto Principal**: Architecture é **largely orthogonal** à funcionalidade do sistema.

- **Mesma funcionalidade pode ter múltiplas arquiteturas**
- **Mesma arquitetura pode suportar funcionalidades diferentes**
- **Mas arquitetura pobre pode fazer ambas difficult**

### 7.7 A Questão do "Big Ball of Mud"

> "If you do not consciously choose the architecture of your systems,
> then it end up being a big ball of mud"

**Big Ball of Mud**: Software system que **lacks perceivable architecture**.

Spaghetti code - sem estrutura discernível.

---

## 8. ABORDAGEM ORIENTADA POR RISCOS (RISK-DRIVEN ARCHITECTURE)

### 8.1 Conceito Central: Failure

> "The concept of failure is central to the design process, and it is
> by thinking in terms of obviating failure that successful designs are achieved."
> — Henry Petroski, 1994

**Axioma de Engenharia**: Avoiding failure é central a toda engenharia.

Técnicas arquitecturais podem ser usadas para **mitigar risks**.

Designers descartam designs **predestinados a falhar**, preferindo aqueles com **low risk de failure**.

**Building successful software = anticipating possible failures**

### 8.2 Definição de Risk

**Risk Formula**:
```
Risk = Probability of failure × Impact of failure
```

**Características**:
- Probability e impact não certos (difíceis de medir precisamente)
- **Um risk pode existir mesmo sem consequences materializarem**
- Risk pode ser stated categorically, frequentemente como **falta de quality attribute necessário**
- Melhor descrever risks como **testable failure scenarios**

**Exemplo**:
```
RUIM: "System may not scale to many users"

BOM: "During peak loads, customers experience user
interface latencies greater than five seconds"
(Testable, measurable)
```

### 8.3 Risk-Driven Approach (3 Passos)

**Questões Fundamentais**:
- How much software architecture work should be done?
- Which techniques should be used?

**Resposta**: Risk-driven approach guida arquitetos a aplicar **minimal set de techniques** para reduzir **most pressing risks**.

**Três Passos**:

1. **IDENTIFY & PRIORITIZE Risks**
   - Identificar risks que ameaçam projeto
   - Priorizar por: Impact + Probability

2. **SELECT & APPLY Techniques**
   - Selecionar técnicas arquiteturais apropriadas
   - Aplicar para mitigar risks prioritizados

3. **EVALUATE Risk Reduction**
   - Verificar se risks foram suficientemente mitigados
   - Reiterativo se necessário

**Princípio Core**:
> "Architecture efforts should be proportional with the risk of failure"

### 8.4 Kinds of Risks

**Categorias**:
- **Project management risks** (lead hit by bus, client needs misunderstood)
- **Software engineering risks** (parsing bugs, system collapse if changed)

**Domain-Specific Risks**:

| Domain | Typical Risks |
|--------|---------------|
| **IT Systems** | Complex, poorly understood problem |
| **Integration** | Domain knowledge scattered |
| **Systems** | Performance, Reliability, Security, Concurrency |
| **Web** | Security, Scalability, Developer productivity |

### 8.5 Design Styles Baseados em Risk

Quanto design upfront fazer? **Três estilos**:

#### **NDUF** (No Design UpFront) - Evolutionary Design

Design cresce conforme sistema é implementado.

Agile practices mitigam shortcomings:
- **Refactoring** limpa designs locais não coordenados
- **Test-Driven Development** garante changes não quebram funcionalidade
- **Continuous Integration** fornece team mesmo codebase

#### **BDUF** (Big Design UpFront) - Planned Design

Arquitetura detalhada **antes construção**.

Analogias com bridges: construção raramente começa antes design finalizado.

Poucos advocam BDUF para **sistema software completo**.

> "BDUF is dumb, but doing NDUF is even dumber" — Dave Thomas

Útil quando **múltiplas teams paralelas** compartilham uma arquitetura.

Mesmo em BDUF, arquitetura **raramente 100% completa** antes prototyping/coding.

#### **LDUF** (Little Design UpFront) - Minimal Planned Design

**Hybrid style** balancing planned + evolutionary design.

Estratégia: **Initial planned design** para garantir arquitetura handles biggest risks.

Mudanças futuras em requirements: **local design ou evolutionary design**.

**Ideia**: Architecture-focused design para setup inicial handle biggest risks. Freedom nos outros design decisions.

### 8.6 Esforço Proporcional aos Riscos

**Propriedade**: Design effort **diretamente proporcional ao risk de failure**.

**Dinâmica**:
- Quando arquitectos **não preocupados** com security risks: **sem tempo** em security design
- Quando performance é **critical risk**: address até atingir acceptable level
- Risk-driven approach: **only design areas com perceived failure risks**

**Consequência**:
- Architecture model será **detailed em algumas areas**
- **Sketchy ou até non-existent em outras areas**
- Modelos são **intermediate products**
- Pode-se parar trabalhando models uma vez convencido que architecture é suitable para addressing risks

---

**[Continua com Parte III: Estilos Arquitecturais, Padrões, Tácticas, Refactoring e Integração]**