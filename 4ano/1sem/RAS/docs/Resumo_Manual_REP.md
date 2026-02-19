# Resumo Executivo: Requisitos em Projetos de Engenharia

Software engineering é uma disciplina composta por um conjunto de teorias, métodos e ferramentas necessárias para desenvolver sistemas de software. O principal objetivo é desenvolver software com qualidade, dentro do prazo e orçamento estabelecidos satisfazendo as necessidades dos clientes.

---

## 1. ENGENHARIA E SISTEMAS (Capítulo 1)

### Conceitos Fundamentais

#### Sistema
- **Definição**: Conjunto identificável e coerente de componentes que interagem para atingir um objetivo dado
- **Características principais**:
  - Propriedades emergentes (o todo é maior que a soma das partes)
  - Fronteira que separa o sistema do ambiente
  - Perspetiva relativista (definição depende do observador/objetivo)

#### Projeto
- **Definição**: Empreendimento temporário, composto por atividades coordenadas com datas início/fim definidas, para criar um sistema único
- **Diferenças com atividades correntes**: 
  - Produz sistemas com características únicas
  - Período definido de execução
  - Estrutura organizacional muda após conclusão

#### Engenharia
- **Definição**: Aplicação de conhecimento científico e técnico para resolver problemas, conceber e construir artefatos úteis
- **Objetivos**: Satisfazer necessidades sociais, reduzir custos, aumentar confiabilidade e desempenho
- **Restrições**: Funciona sob limitações de tempo e orçamento (requer trade-offs)

#### Engenharia de Sistemas
- **Definição**: Ramo interdisciplinar que aplica abordagem sistemática ao desenvolvimento de sistemas complexos e heterogéneos
- **Duas perspetivas**:
  1. Engenharia de sistemas como produto (sistemas com múltiplas tecnologias: software, hardware, mecânico)
  2. Abordagem sistemática ao processo (metodologia rigorosa independente da tecnologia)

### Complexidade em Engenharia

#### Gestão da Complexidade
- **Reductionist**: Decompor sistema em partes menores; cuidado: propriedades emergentes podem desaparecer
- **Holística**: Considerar sistema como um todo; evita perder as propriedades emergentes
- **Abstração**: Escolher nível adequado de detalhe em cada momento

#### Ciclo de Vida do Sistema
**Fases genéricas**:
1. **Estudo de viabilidade**: Decidir sobre relevância e viabilidade (fatores económicos, tecnológicos, comerciais)
2. **Análise**: Documentar funcionalidades e restrições
3. **Design**: Definir estrutura interna, componentes e funcionalidades
4. **Implementação**: Construir o sistema
5. **Teste**: Avaliar conformidade com requisitos e identificar defeitos
6. **Utilização**: Sistema em operação no ambiente real
7. **Manutenção**: Corrigir defeitos e melhorar sistema

---

## 2. ENGENHARIA DE SOFTWARE (Capítulo 2)

### 2.1 Definição e Características

#### 2.1.1 Engenharia de Software
- **Definição**: Aplicação de abordagem sistemática, disciplinada e quantificável no contexto de planeamento, desenvolvimento e exploração de sistemas software
- **Objetivo principal**: Desenvolver sistemas software com qualidade, dentro do orçamento, prazos e satisfazendo necessidades reais dos clientes
- **Qualidade**: Conformidade com os requisitos

#### 2.1.2 Diferença: Programação vs Engenharia de Software
- **Programação**: Atividade individual, escrever código completo
- **Engenharia de software**: Atividade coletiva; engenheiro software gasta ~90% do tempo em atividades não-programação
- Software engineer coordena programadores; é análogo à relação civil engineering vs construção civil

### 2.2 SWEBOK - Knowledge Areas (15 KAs)
| Área | Descrição |
|------|-----------|
| **1. Software Requirements** | Elicitação, análise, documentação, validação, manutenção de requisitos |
| **2. Software Design** | Definição de arquitetura, componentes, interfaces |
| **3. Software Construction** | Implementação, validação, testes de código |
| **4. Software Testing** | Avaliação de qualidade, identificação de defeitos |
| **5. Software Maintenance** | Correção de defeitos, adaptação a novos contextos |
| **6. Software Configuration Management** | Controlo de mudanças, rastreabilidade |
| **7. Software Engineering Management** | Planeamento, coordenação, monitorização |
| **8. Software Engineering Process** | Avaliação e melhoria do processo |
| **9. Models and Methods** | Ferramentas sistemáticas para desenvolvimento |
| **10. Software Quality** | Aspetos não-funcionais: usabilidade, eficiência, portabilidade, confiabilidade |
| **11. Professional Practice** | Profissionalismo, ética, comunicação |
| **12. Software Economics** | Análise económica, ROI, cost-benefit |
| **13-15. Foundations** | Computação, matemática, engenharia |

### 2.3 Características do Software

#### 2.3.1 Definição de Software
- **Conjunto** de programas, procedimentos, regras e documentação
- **Elemento abstrato** que, com hardware, constitui parte automatizada de um sistema
- **Implementa** mecanismo estímulo-resposta para satisfazer necessidades externas

#### 2.3.2 Tipos de Software
- **System software**: Gere recursos de hardware (SO, drivers, servidores)
- **Application software**: Ferramentas produtivas para utilizadores (editores, folhas de cálculo)

#### 2.3.3 Classificação de Software (5 eixos)
1. **Dificuldade do problema**: Problemas novos/sem solução vs problemas resolvidos
2. **Relação temporal**: Estático (todos inputs de uma vez) vs Dinâmico (inputs contínuos)
3. **Tarefas simultâneas**: Sequencial vs Paralelo
4. **Aspeto crítico**: Data-driven vs Interactive vs Control-driven
5. **Determinismo**: Determinístico (mesmos inputs → mesmos outputs) vs Não-determinístico

### 2.4 Modelos de Desenvolvimento

#### 2.4.1 Waterfall (Cascata)
- **Caraterística**: Fases sequenciais e distintas
- **Fases**: Análise → Design → Implementação → Testes → Manutenção
- **Vantagem**: Clareza de fases
- **Desvantagem**: Inflexível a mudanças. Não é possível retroceder fases facilmente

**Análise**: Requisitos são completamente definidos antes do design começar

**Design**: Arquitetura e componentes são definidos com base nos requisitos

**Implementação**: Código é escrito conforme design especificado

**Testes**: Sistema é testado contra requisitos definidos

**Manutenção**: Correção de defeitos e melhorias após entrega

#### 2.4.2 Incremental e Iterativo
- **Caraterística**: Desenvolvimento em múltiplas versões, cada uma refinando a anterior
- **Vantagem**: Flexibilidade, feedback rápido
- **Desvantagem**: Gestão mais complexa

#### 2.4.3 Transformacional
- **Caraterística**: Especificação executável; código gerado automaticamente
- **Vantagem**: Reduz esforço de implementação manual
- **Desvantagem**: Requer especificação muito precisa

#### 2.4.4 Espiral
- **Caraterística**: Ciclos de análise → design → implementação → avaliação de risco
- **Vantagem**: Gestão de risco contínua
- **Desvantagem**: Complexidade de gestão

---

## 3. REQUISITOS (Capítulo 3)

### Definição de Requisito

**Requisito**: Propriedade, capacidade ou condição que um sistema deve satisfazer. Pode ser:
- Necessidade ou expectativa de stakeholders
- Restrição imposta ao sistema
- Condição legal ou regulatória

### Tipos de Requisitos

#### Requisitos Funcionais
- **O que são**: Descrevem funções, serviços e comportamentos do sistema
- **Exemplo**: "O sistema deve permitir ao utilizador criar uma nova conta"
- **Teste**: Verificável através de testes dinâmicos

#### Requisitos Não-Funcionais
- **O que são**: Descrevem qualidades, restrições e características de desempenho

**Categorias principais**:

1. **Aparência**: Look and feel visual do sistema
2. **Usabilidade**: Facilidade de aprendizado e uso
   - Exemplo: "Interface deve ser compreensível por utilizadores sem treino técnico"
3. **Desempenho**: Velocidade, recursos, throughput
   - Exemplo: "Resposta às queries em menos de 5 segundos"
4. **Operacional**: Ambiente, hardware, frequência de uso
   - Exemplo: "Funcionar 24/7 com 99.9% uptime"
5. **Manutenção e Suporte**: Correção de defeitos, adaptabilidade
   - Exemplo: "Código deve ser compreensível por novo programador em menos de 3 dias"
6. **Segurança**: Proteção, controlo de acesso, criptografia
   - Exemplo: "Passwords com mínimo 12 caracteres"
7. **Legal**: Conformidade com leis, standards
   - Exemplo: "Cumprir GDPR para dados pessoais"
8. **Política e Cultural**: Restrições organizacionais, preferências
   - Exemplo: "Usar apenas open-source components"

### Classificação Alternativa

#### Requisitos do Utilizador vs Requisitos do Sistema
- **Utilizador**: Descrição em linguagem natural de funcionalidades para utilizadores finais
  - "O cliente pode guardar programas favoritos para ver quando quiser"
- **Sistema**: Descrição técnica detalhada para implementadores
  - "O subsistema de gravação deve aceitar até 100 programas em simultâneo"
  - Geralmente mais formal, específico, detalhado

### Conceitos Relacionados

- **Especificação**: Documento que descreve o que deve ser implementado
- **Desenho/Design**: Descrição de como implementar (vem após requisitos)
- **Objetivo**: O que se quer atingir (exemplo: lucro de €1M)
- **Restrição**: Limitação imposta (exemplo: orçamento máximo de €500k)

---

## 4. ENGENHARIA DE REQUISITOS (Capítulo 4)

### Definição

**Engenharia de Requisitos**: Conjunto de atividades que permitem elicitar, negociar e documentar funcionalidades e restrições de um sistema em desenvolvimento

### Atividades Principais

1. **Elicitação**: Obter requisitos de stakeholders e outras fontes
2. **Análise**: Compreender, refinar, resolver conflitos entre requisitos
3. **Documentação**: Registar requisitos de forma clara e estruturada
4. **Validação**: Garantir que requisitos representam efetivamente necessidades
5. **Negociação**: Resolver conflitos entre stakeholders
6. **Priorização**: Ordenar requisitos por importância/urgência
7. **Rastreabilidade**: Manter ligações entre requisitos e artefatos de design/implementação

### Desafios e Problemas Comuns

#### Problemas na Elicitação
- Requisitos incompletos ou mal compreendidos
- Falta de envolvimento de stakeholders chave
- Comunicação pobre entre desenvolvimento e clientes
- Mudança de requisitos durante projeto

#### Problemas na Documentação
- Ambiguidades em linguagem natural
- Requisitos vagos ou não verificáveis
- Falta de rastreabilidade
- Inconsistências entre requisitos

#### Problemas na Gestão
- Mudanças de requisitos não controladas
- Escopo não definido claramente
- Conflitos não resolvidos entre stakeholders
- Prioridades indefinidas

### Princípios Fundamentais

- **Comunicação**: Estabelecer canais efetivos entre stakeholders
- **Completude**: Garantir que todos os aspetos são cobertos
- **Consistência**: Evitar contradições entre requisitos
- **Rastreabilidade**: Manter ligações throughout do lifecycle
- **Flexibilidade**: Permitir mudanças controladas quando necessário

---

## 5. ELICITAÇÃO DE REQUISITOS (Capítulo 5)

### Processo de Elicitação

**Cinco passos principais**:
1. **Estudar o domínio**: Compreender contexto e negócio
2. **Identificar fontes de requisitos**: Encontrar stakeholders e artefatos relevantes
3. **Consultar e envolver stakeholders**: Comunicar e coletar informação
4. **Selecionar técnicas**: Escolher métodos apropriados
5. **Elicitar requisitos**: Aplicar técnicas e registar resultados

### Identificação de Stakeholders

**Definição**: Pessoa, grupo ou organização que tem interesse legítimo no sistema

**Tipos principais**:

1. **Utilizadores Finais**: Operam o sistema diretamente
   - Priorizar utilizadores mais frequentes
   - Considerar necessidades especiais: pessoas com deficiência, baixa literacia, barreiras linguísticas

2. **Clientes/Proprietários**: Pagam e usam o sistema
   - Interesse em valor de negócio e ROI

3. **Gestores/Supervisores**: Supervisionam trabalho dos utilizadores
   - Interesse em produtividade e conformidade

4. **Desenvolvedor/Equipa técnica**: Implementa o sistema
   - Interesse em viabilidade técnica

5. **Inspetores/Auditores**: Verificam conformidade
   - Interesse em segurança, qualidade, compliance

6. **Stakeholder Negativo**: Opõe-se ao sistema
   - Importante para identificar resistências e objeções

### Técnicas de Elicitação

#### Técnicas com Indivíduos

**Entrevistas**
- **O que são**: Conversa estruturada entre analista e stakeholder
- **Vantagem**: Flexibilidade, aprofundamento
- **Desvantagem**: Tempo intensivo, viés
- **Quando usar**: Quando relação é importante, informação complexa

**Questionários/Surveys**
- **O que são**: Conjunto estruturado de perguntas
- **Vantagem**: Escalável, quantitativo
- **Desvantagem**: Falta de profundidade, baixa taxa de resposta
- **Quando usar**: Grande número de stakeholders, perguntas simples

**Introspeção**
- **O que é**: Analista imagina-se no papel do utilizador
- **Vantagem**: Rápido, inicial
- **Desvantagem**: Viés pessoal, falta de validação
- **Quando usar**: Apenas como ponto de partida, deve ser complementada

**Etnografia/Observação**
- **O que é**: Analista observa utilizadores executando atividades
- **Vantagem**: Compreensão realista de processos
- **Desvantagem**: Efeito Hawthorne (pessoas mudam comportamento quando observadas)
- **Quando usar**: Processos complexos, falta de comunicação entre stakeholders

**Aprendizado/Mentoring**
- **O que é**: Analista aprende e executa tarefas com utilizador
- **Vantagem**: Compreensão profunda, construir confiança
- **Desvantagem**: Tempo intensivo
- **Quando usar**: Domínio complexo, utilizador é especialista

#### Técnicas com Grupos

**Brainstorming**
- **Processo**: Grupo (5-12 pessoas) gera ideias livremente, sem crítica
- **Vantagem**: Criatividade, múltiplas perspetivas
- **Desvantagem**: Requer animador competente, alguns dominam discussão
- **Moderação**: Evitar crítica imediata, incluir todos

**Focus Groups**
- **Processo**: Discussão aprofundada sobre tópico específico
- **Vantagem**: Dinâmica de grupo, descoberta de conflitos
- **Desvantagem**: Dificuldade em organizar, viés de grupo

**JAD (Joint Application Design)**
- **Processo**: Sessões estruturadas com representantes de múltiplos stakeholders
- **Vantagem**: Consenso rápido, envolvimento
- **Desvantagem**: Requer envolvimento total de participantes

**Oficinas de Requisitos**
- **Processo**: Reuniões estruturadas com facilitador
- **Objetivo**: Identificar, negociar e aprovar requisitos

#### Técnicas com Artefatos

**Análise de Documentos Existentes**
- Analisar sistemas similares, legislação, standards
- Exemplo: Estudar sistema legado que será substituído

**Protótipos**
- **O que é**: Versão funcional simplificada do sistema
- **Objetivo**: Validar compreensão de requisitos com stakeholders
- **Tipo**: Can be paper-based, wireframes, ou código

**User Stories** (Agile)
- **Formato**: "Como [utilizador], quero [funcionalidade], para que [benefício]"
- **Exemplo**: "Como cliente, quero guardar items no carrinho, para que possa comprar depois"
- **Vantagem**: Simples, utilizador-focado
- **Desvantagem**: Pode ser vago, requer detalhe adicional

**Storyboards**
- **O que é**: Sequência de desenhos mostrando interação utilizador
- **Vantagem**: Visual, fácil de comunicar
- **Quando usar**: Procesos com sequência clara de passos

---

## 6. NEGOCIAÇÃO E PRIORIZAÇÃO DE REQUISITOS (Capítulo 6)

### Negociação de Requisitos

#### Definição
**Negociação**: Processo de discussão entre stakeholders com interesses potencialmente conflituosos para chegar a acordo sobre requisitos a implementar

#### Processo de Negociação

1. **Identificar conflitos**: Encontrar requisitos contraditórios ou incompatíveis
2. **Compreender perspetivas**: Ouvir todos os stakeholders
3. **Explorar alternativas**: Brainstorm soluções
4. **Negociar compromissos**: Encontrar solução aceitável para todos
5. **Documentar acordo**: Registar decisão e racional

#### Posturas e Estratégias de Negociação

**Cooperativa** (Win-Win)
- Objetivo: Solução que beneficia todos
- Método: Expansão de recursos, creative solutions
- Melhor a longo prazo

**Competitiva** (Win-Lose)
- Objetivo: Maximizar ganho próprio
- Método: Pressão, argumentação forte
- Pode gerar ressentimento

**Evitativa** (Adiar)
- Objetivo: Aiar conflito
- Risco: Problema fica sem resolver

**Compromisso** (Split the Difference)
- Objetivo: Cada parte cede algo
- Pode deixar todos insatisfeitos

### Priorização de Requisitos

#### Definição
**Priorização**: Ordenar requisitos por importância, urgência ou valor

#### Critérios de Priorização

- **Valor de negócio**: Quanto gera revenue ou reduz custo
- **Risco técnico**: Dificuldade de implementação, dependências
- **Dependências**: Requisitos que dependem de outros
- **Urgência**: Quanto rápido é necessário
- **Impacto**: Quantas pessoas afeta
- **Compliance**: Obrigações legais ou regulatórias

#### Técnicas de Priorização

**MoSCoW**
- **Must** (Obrigatório): Crítico para sucesso
- **Should** (Deveria): Importante, mas pode atrasar-se
- **Could** (Poderia): Desejável, mas não crítico
- **Won't** (Não será): Propositadamente excluído nesta versão
- **Vantagem**: Simples, intuitivo
- **Uso**: Iterações de desenvolvimento

**Escala Numérica** (1-10)
- Cada stakeholder classifica requisito
- Scores agregados e comparados
- **Vantagem**: Quantitativo, fácil comparação
- **Desvantagem**: Pseudo-precisão

**Técnica de Pesos**
- Atribuir peso a cada critério
- Score = Σ(critério_i × peso_i)
- **Vantagem**: Incorpora múltiplos critérios
- **Desvantagem**: Subjetivo na atribuição de pesos

**Análise de Dependências**
- Mapear quais requisitos dependem de outros
- Priorizar dependências primeiro
- **Vantagem**: Evita bloqueios de implementação

---

## 7. ESCRITA EM LINGUAGEM NATURAL (Capítulo 7)

### Princípios de Escrita de Requisitos

#### Diretrizes Recomendadas

**1. Formato Padrão**
- Usar template consistente em todos requisitos
- Exemplo: "O sistema deve [verbo] [objeto] [condições]"
- Vantagem: Consistência, facilita parsing automático

**2. Frases Curtas**
- Máximo 1-2 linhas por requisito
- Máximo 1-2 ideias por frase
- Exemplo (Bom): "O sistema guarda dados de utilizador no MySQL"
- Exemplo (Mau): "O sistema guarda dados de utilizador no MySQL, SQL Server ou Oracle e protege com encriptação 256-bit de forma que apenas o utilizador pode aceder aos dados"

**3. Vocabulário Limitado**
- Usar termos consistentemente
- Exemplo: Se "utilizador" é o termo, não usar "cliente", "pessoa", "ator"
- Evitar sinónimos que possam criar confusão
- Cuidado com acrónimos: usar apenas com explicação ou termos estabelecidos (ERP, PDF)

**4. Verbos Precisos**
- Usar verbos concretos: "criar", "atualizar", "deletar", "guardar"
- Evitar: "tratar", "processar", "manipular", "suportar" (vago)
- Preferir "deve" ("shall") a "pode" ou "deveria"

**5. Verificabilidade**
- Requisito deve ser testável, mensurável
- Evitar: "fácil de usar", "robusto", "eficiente"
- Preferir: "resposta em menos de 5 segundos", "99.9% uptime", "90% de utilizadores conseguem tarefa em menos de 2 minutos"

#### Diretrizes a Evitar

**1. Ambiguidade**
- Homónimos: Mesma palavra, significados diferentes
  - "left" = passado ou oposto de direita
- Polissemia: Mesma palavra, significados relacionados
  - "coffee" = fruto ou bebida

**2. Conjunções Problemáticas**
- "e" vs "ou": Significados podem ser idênticos ou distintos
  - "homens e mulheres" = ambos
  - "homens ou mulheres" = um ou outro
  - "homens altos e finos" = ambos altos E finos, ou altos OU finos?
- Evitar "e/ou" (fonte de ambiguidade)
- Cuidado com enumerações e "e" final

**3. Terminologia Vaga**
- Evitar: "fácil", "versátil", "intuitivo", "moderno", "aproximadamente", "mínimo", "eficiente"
- Problema: Não verificável, interpretação subjetiva
- Alternativa: Quantificar ou ser específico
  - Vago: "Resposta rápida"
  - Preciso: "Resposta em menos de 5 segundos para 95% das queries"

**4. Ambiguidade em Contexto**
- Evitar pronomes que se referem a múltiplos antecedentes
- Evitar frases complexas com múltiplos níveis
- Usar repetição em vez de sinónimos para clareza

### Estrutura de Documento de Requisitos

**Secções típicas** (27 possíveis):

1. **Prefácio**: Data, versão, autores
2. **Tabela de Conteúdos**
3. **Introdução**: Contexto, objetivos do sistema
4. **Descrição Geral**: Perspetiva de produto, funções principais
5. **Requisitos Específicos**: Requisitos funcionais e não-funcionais detalhados
6. **Índices**: Índice alfabético, referências cruzadas
7. **Apêndices**: Exemplos, glossário, diagramas

**Template para cada requisito**:
- ID único
- Descrição
- Prioridade
- Status
- Responsável
- Data de criação/modificação
- Rastreabilidade (ligações a design/teste)

### Ambiguidade em Linguagem Natural

#### O que é Ambiguidade

**Definição**: Existência de duas ou mais interpretações possíveis para uma frase

#### Tipos de Ambiguidade

**1. Lexical (Palavras)**
- Homónimos: "left" (past of leave, ou opposite of right)
- Polissemia: "coffee" (fruit ou drink)
- **Solução**: Contexto geralmente resolve; se não, reescrever

**2. Syntactic (Estrutura)**
- Pronomes ambíguos: "The managers inform the directors and secretaries, because they are responsible"
  - Quem é responsible? Directors, secretaries, ou ambos?
- **Solução**: "The managers inform the directors and secretaries, because the latter are responsible"

**3. Semântica (Significado)**
- Conjunções: "and" vs "or"
- Enumerações: "and" antes do último item
- **Solução**: Repetir verbo ou usar clarificador ("both", "each", "acting collectively")

#### Abordagens para Reduzir Ambiguidade

1. **Escrever menos ambiguamente**
   - Reformular sentences
   - Usar estrutura clara
   - Evitar compressão excessiva

2. **Detetar ambiguidade**
   - Manualmente: Releitura crítica
   - Com ferramentas: Checkers automáticos
   - Testes com utilizadores: Peça a terceiros para interpretar

3. **Usar linguagem restrita**
   - Templates estruturados
   - Vocabulário limitado definido
   - Tradeoff: Menos natural, mais preciso

---

## 8. MODELAÇÃO (Capítulo 8)

### Definição de Modelo

**Modelo**: Representação abstrata e simplificada de um sistema com objetivo específico

**Características**:
- Abstrai detalhes irrelevantes
- Mantém aspetos relevantes para objetivo
- Permite comunicação entre stakeholders
- Facilita análise e validação

### Dimensões de Modelos

**1. Perspetiva Temporal**
- **Estática**: Estrutura do sistema em ponto específico de tempo
- **Dinâmica**: Comportamento ao longo do tempo

**2. Perspetiva de Abstração**
- **Conceitual**: Alto nível, sem detalhes técnicos
- **Lógica**: Nível intermédio, mais específica
- **Física**: Baixo nível, detalhes implementação

**3. Completude**
- **Parcial**: Modelo incompleto
- **Completa**: Todas as informações necessárias

### Conceitos de Modelação

#### Sistema e Modelo
- **Sistema real**: Entidade que queremos compreender
- **Modelo**: Representação simplificada para objetivo específico
- **Relação**: Modelo mantém mapeamento com sistema real

#### Especificação
**Definição**: Descrição de propriedades e comportamento esperado do sistema

**Propósito**:
- Comunicação entre stakeholders
- Base para implementação
- Validação que sistema foi implementado corretamente

#### Linguagem de Modelação
- **Formal**: Sintaxe e semântica precisamente definidas (exemplo: UML)
- **Semi-formal**: Estrutura mas alguma flexibilidade
- **Informal**: Descrição em linguagem natural

#### Modelos Mentais
**Definição**: Representação cognitiva que pessoa tem de sistema

**Importância**:
- Cada stakeholder tem modelo mental diferente
- Modelação formal ajuda a alinhar modelos mentais

#### Modelo de Computação
**Definição**: Abstração de como sistema processa informação

**Exemplos**:
- Reactive (responde a eventos)
- Proactive (executa por própria iniciativa)
- Hybrid (combinação)

### Modelos para Requisitos

#### Domain Models
- **O que representam**: Conceitos e relações principais do domínio de negócio
- **Quando usar**: Entender contexto e vocabulário
- **Exemplo**: Classes: Customer, Order, Product e suas relações
- **Técnica**: Diagramas de classe simplificados

#### Use Case Models
- **O que representam**: Interações entre sistema e atores (utilizadores externos)
- **Componentes principais**:
  - Atores: Utilizadores ou sistemas externos
  - Use cases: Sequências de ações que resultam em valor
  - Relações: Include (obrigatório), Extend (opcional)
- **Exemplo Use Case**: "Login" (ator: utilizador, ações: inserir credentials, validar, aceder)
- **Vantagem**: Foco em funcionalidade visível externamente
- **Leitura**: "O sistema deve permitir ao utilizador X fazer Y"

#### Class Models
- **O que representam**: Estrutura de dados do sistema, classes e relações
- **Componentes**:
  - Classes: Tipo de objeto
  - Atributos: Dados associados
  - Métodos: Operações
  - Relações: Association, inheritance, composition
- **Quando usar**: Entender estrutura de dados necessária
- **Exemplo**: Class Order com atributos orderID, date, items; método calculateTotal()

#### Sequence Models (Sequence Diagrams)
- **O que representam**: Ordem e timing de mensagens entre objetos
- **Quando usar**: Entender fluxo de interações
- **Exemplo**: Utilizador → Sistema: "login()" → Database: "query user" → Response
- **Vantagem**: Mostra temporalidade e ordem
- **Leitura**: De cima para baixo, mensagens entre atores/objetos

#### State Models (State Diagrams)
- **O que representam**: Possíveis estados de uma entidade e transições entre estados
- **Componentes**:
  - Estados: Condições que a entidade pode ter
  - Transições: Mudanças entre estados (com condições/eventos)
  - Initial e Final states
- **Exemplo**: Order states: Created → Paid → Shipped → Delivered
  - Transição: Paid → Shipped ocorre quando "delivery scheduled = true"
- **Quando usar**: Lógica complexa de estados, workflows
- **Vantagem**: Garante que todas as transições válidas estão definidas

#### Activity Models (Activity Diagrams)
- **O que representam**: Fluxo de atividades, processos de negócio
- **Componentes**:
  - Atividades: O que é feito
  - Decisões: Branches condicionais
  - Sincronização: Atividades paralelas
  - Swimlanes: Responsabilidades por ator
- **Quando usar**: Entender fluxos de processo
- **Exemplo**: Workflow de aprovação de pedido
  - Analista avalia → Se OK, vai para production; se não, retorna para designer
- **Vantagem**: Perspetiva de processo, paralelismo

### Benefícios da Modelação

- **Comunicação**: Facilita discussão entre stakeholders
- **Completude**: Força a pensar em todos os aspetos
- **Consistency**: Identifica contradições
- **Validation**: Permite validar requisitos antes de implementação
- **Rastreabilidade**: Ligações entre requisitos e design

---

## 9. SUMÁRIO DE IDEIAS-CHAVE

### Dimensões Críticas

**1. Clareza**
- Definições precisas de termos
- Linguagem clara e sem ambiguidade
- Verificabilidade de requisitos

**2. Completude**
- Todos os stakeholders representados
- Todas as funcionalidades cobradas
- Requisitos funcionais E não-funcionais

**3. Consenso**
- Acordos negociados entre stakeholders
- Prioridades definidas
- Compromissos documentados

**4. Rastreabilidade**
- Cada requisito ligado a fonte
- Ligações entre requisitos
- Ligações a design e implementação

**5. Adaptabilidade**
- Processo para lidar com mudanças
- Controlo de versões
- Re-avaliação conforme projeto avança

### Problemas Mais Comuns

| Problema | Causa | Solução |
|----------|-------|--------|
| Requisitos incompletos | Stakeholders não envolvidos | Identificar todos stakeholders cedo |
| Ambiguidade | Linguagem natural imprecisa | Usar templates, limitar vocabulário |
| Conflitos não resolvidos | Falta de negociação | Sesões estruturadas de negociação |
| Mudanças incontroladas | Sem processo de change management | Aprovar mudanças através comissão |
| Falta de rastreabilidade | Sem sistema de tracking | Usar ferramenta de gestão requisitos |
| Teste impossível | Requisitos não verificáveis | Usar critérios SMART |

### Competências Requeridas

**Analista de Requisitos deve ter**:
- Questionamento: Fazer perguntas certas
- Observação: Ver além do óbvio
- Discussão: Argumentar com respeito
- Negociação: Encontrar compromissos
- Antecipação: Imaginar futuras necessidades
- Organização: Estruturar informação
- Comunicação: Clara e concisa

---

## 10. GLOSSÁRIO RESUMIDO

- **Artefato**: Produto tangível criado durante desenvolvimento (documento, código, modelo)
- **Análise**: Fase de compreensão de requisitos e resolução de conflitos
- **Ciclo de Vida**: Sequência de fases de um sistema desde conceção até descomissionamento
- **Comunicação**: Troca de informação entre stakeholders
- **Completude**: Propriedade de ter todas as informações necessárias
- **Conflito**: Requisitos contraditórios ou incompatíveis
- **Consistência**: Ausência de contradições
- **Elicitação**: Processo de obtenção de requisitos junto de stakeholders
- **Engenharia**: Aplicação de conhecimento científico para resolver problemas
- **Especificação**: Descrição precisa de o que deve ser implementado
- **Estabilidade**: Requisitos mantêm-se através de tempo
- **Fase**: Agrupamento de atividades em projeto
- **Flexibilidade**: Capacidade de sistema se adaptar a mudanças
- **Funcionalidade**: Capacidade do sistema fazer algo útil
- **Implementação**: Construção do sistema
- **Interface**: Ponto de interação entre sistema e ambiente
- **Iteração**: Repetição de processo para refinar resultado
- **Modelo**: Representação abstrata simplificada de sistema
- **Monitorização**: Observação contínua de progresso
- **Necessidade**: O que stakeholder precisa ou quer
- **Negociação**: Discussão entre stakeholders para acordo
- **Não-funcional**: Requisito de qualidade ou restrição
- **Objetivo**: O que se quer atingir
- **Processo**: Sequência de atividades para atingir resultado
- **Prioridade**: Ordenação de importância/urgência
- **Projeto**: Empreendimento temporário para criar sistema único
- **Qualidade**: Conformidade com requisitos e expectativas
- **Rastreabilidade**: Capacidade de ligar requisito a fonte e implementação
- **Recursão/Iteração**: Aplicação repetida de processo
- **Risco**: Possibilidade de evento negativo
- **Rol/Responsabilidade**: Função de pessoa em projeto
- **Stakeholder**: Pessoa ou grupo com interesse no sistema
- **Sistema**: Conjunto coerente de componentes interagindo para objetivo
- **Teste/Validação**: Verificação de conformidade com requisitos
- **Utilização**: Fase de sistema em operação normal
- **Utilizador**: Pessoa que opera o sistema
- **Validação**: Verificação de que certo requisito foi satisfeito

---

**Documento Preparado com Base em**: Manual "Requirements in Engineering Projects" de João M. Fernandes e Ricardo J. Machado (Universidade do Minho, 2016)

**Nota**: Este resumo consolida as definições e ideias-chave do manual. Para aprofundamento, consulte o manual original que inclui exemplos detalhados, exercícios e referências adicionais.