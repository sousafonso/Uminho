# ELICITAÇÃO DE REQUISITOS: TÉCNICAS E STAKEHOLDERS

## 4.1 Processo de Elicitação

Permite compreender **quais são os requisitos** de um determinado sistema.

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

---

## 4.2 Identificação de Stakeholders

### 4.2.1 Definição de Stakeholder

**Stakeholder**: Pessoa materialmente afetada pela implementação do sistema.

OU

**Stakeholder**: Pessoa com algum tipo de interesse legítimo no sistema.

O "interesse" é também amplo: resultar de utilização, ser afetado, ou ter responsabilidade em relação ao sistema.

### 4.2.2 Tipos de Stakeholders
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

##### **Market Segment** (Segmento de Mercado)

Caracterização de necessidades e comportamentos comuns de clientes:

Um grupo de clientes representa um segmento de mercado distinto se:
1. Necessidades demandam e justificam oferta diferente
2. Abordados através de canais distribuição distintos
3. Necessitam de tipos relações diferentes
4. Têm significativamente níveis de profit distintos
5. Estão dispostos a pagar por aspetos diferentes da oferta

##### **Negative Stakeholder** (Stakeholder Negativo)

Pessoa que **deseja que sistema NÃO seja desenvolvido**.

Atitude pode variar: Oposição pacífica a hostilidade ativa.

Identificação permite:
- Identificar tentativas de sabotagem
- Compreender relações pessoais e políticas na organização
- A sua presença em elicitação é **relevante**

---
## 4.3 Técnicas de Elicitação (11 Técnicas)

### 4.3.1 Competências Genéricas

Engenheiro de requisitos deve dominar: **Questioning, Observing, Discussing, Negotiating, Supposing**

### 4.3.2 Técnicas para Indivíduos

#### **INTERVIEW** (Entrevista)

- Entrevistador tem **grande liberdade**
- Conversas completamente abertas frequentemente produzem resultados pobres
- **Deve ser estruturada**

**Processo** (4 fases):
1. **Identify interviewes** - Selecionar pessoas
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

#### **SURVEY** (Sondagem)

- Técnica usando **questionário** para recolher informação de múltiplos respondentes
- Comum na elicitação inicial de requisitos

**Processo** (5 fases):
1. Identify audience
2. Conceive questionnaire
3. Determine sample
4. Recruit participants
5. Conduct survey



Quando mesmo questionário usado para todas pessoas: possível **processar estatisticamente** respostas.

#### **INTROSPECTION** (Introspecção)

- **Mais básica, óbvia e rudimentar** de todas as técnicas

Analista define requisitos baseado no **que pensa serem necessidades** dos stakeholders.

Engenheiro **coloca-se no papel** do cliente/utilizadores.

Raciocina baseado em premissas: "If I were the client, I would like the product to..."

**Uso**: Extensivamente usado quando engenheiros têm **deep knowledge** do domínio.


#### **DOMAIN ANALYSIS** (Análise de Domínio)

Analisar documentação e estudar sistemas existentes = boa fonte de requisitos.

Pressupostos:
- Analisar sistemas upstream e downstream
- Examinar sistemas com propósitos similares

Objetivo: Examinar **domínio onde sistema localizado**, para identificar **elementos comuns de todos sistemas** no domínio.

**Análise de documentos**: Técnica baseada em procurar requisitos em documentos, relatórios, manuais.


### 4.3.3 Técnicas de Grupo

#### **BRAINSTORMING** (Geração de Ideias)

- Facilita **geração de ideias**
- Sessão congrega grupo de **5 a 12 pessoas**
- Grupo sugere e explora **tantas ideias quanto possível**
- **Sem criticar ou julgar** ideias

**Processo** (2 fases):
1. Generate ideas
2. Consolidate ideas

### 4.3.4 Técnicas de Artefatos

#### **PROTOTYPING** (Prototipagem)

Cliente pode definir apenas objectivos genéricos, sem detalhe do funcionamento.

Abordagem baseada em prototypes pode ser mais adequada.

**Pressupostos**: Processo iterativo.

**Processo** (3 fases):
1. Elicit requirements
2. Construct prototype
3. Test prototype

Prototype serve **apenas como mecanismo para capturar requisitos**.

**Não é construir produto final.**

#### **PERSONA** (Persona)

Técnica comum em advertising, ganhou popularidade recentemente em requirements engineering.

**Persona** = Pessoa fictícia que representa **tipo importante de utilizadores** do produto.

Persona é **arquétipo** das pessoas parte da target audience.

Deve ser concebida para **representar essas pessoas no que é essencial e distintivo**.
