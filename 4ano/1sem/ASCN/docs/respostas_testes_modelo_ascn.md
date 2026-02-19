# Respostas aos Testes Modelo - ASCN
## Aplicações e Serviços de Computação em Nuvem

---

## Teste de 12 de Janeiro de 2022

### Pergunta 1: Complexidade da Replicação em Serviços Multi-camada

**Pergunta Original:**
"A complexidade da replicação de um serviço multi-camada não varia de acordo com o componente alvo (p.ex., servidor web, servidor aplicacional, base de dados) a replicar. Indique e justifique se concorda ou não com esta afirmação."

**Resposta:**

**Discordo completamente.** A complexidade varia significativamente consoante o tipo de componente a replicar.

**Servidor Web (Stateless) - Baixa Complexidade:**
- Sem estado: cada pedido é independente
- Replicação simples: criar múltiplas instâncias
- Sincronização: não necessária entre réplicas
- Exemplo: Replicar Nginx é trivial (10 instâncias idênticas funcionam perfeitamente)
- Load balancer distribui tráfego aleatoriamente

**Servidor Aplicacional (Potencialmente Stateless) - Complexidade Média:**
- Pode ter cache local ou sessões de utilizador
- Se sem estado: simples de replicar
- Se com estado: necessário armazenamento distribuído (Redis, Memcached) para sessões
- Exemplo: Node.js com sessões requer sincronização de sessões entre réplicas

**Base de Dados (Stateful) - Complexidade Muito Alta:**
- Todos os dados devem estar consistentes entre réplicas
- Problemas principais:
  1. **Escrita Distribuída**: Múltiplos clientes escrevem simultaneamente em diferentes réplicas
  2. **Consenso**: Como decidir qual é a versão correta de um dado?
  3. **Eleição de Líder**: Em caso de falha, qual réplica assume o comando?
  4. **Replicação Síncrona vs. Assíncrona**: Trade-off entre consistência e latência
- Exemplo: PostgreSQL com replicação requer configuração complexa (Patroni, streaming replication)
- Necessário resolver problema de consenso distribuído (Paxos, Raft)

**Conclusão:**
A complexidade aumenta exponencialmente ao passar de stateless para stateful:
- Web Server: Trivial
- App Server: Moderado
- Database: Exponencialmente mais complexo

---

### Pergunta 2-4: (Questões não numeradas completas no PDF original)

**Pergunta 3: Qual a estratégia para estimar recursos para WikiJS**

"Imagine que a Universidade do Minho lhe atribui a responsabilidade de instalar a aplicação WikiJS para servir todos os alunos da universidade. No entanto, antes do processo de instalação, o gestor financeiro da universidade pergunta-lhe quais os recursos computacionais que prevê serem necessários para esta instalação. Que estratégia(s) pode aplicar para responder a esta pergunta e ter um elevado grau de confiança que a aplicação será capaz de responder à carga computacional imposta em produção?"

**Resposta:**

Existem três estratégias principais que devem ser usadas em conjunto:

**1. Benchmarking (Avaliação Experimental)**
- Criar ambiente de teste com WikiJS
- Simular carga realista (ex: 5000 alunos simultâneos)
- Medir desempenho: CPU, memória, disco, latência, throughput
- Variar carga progressivamente até encontrar limites
- Fazer múltiplas execuções para validar reprodutibilidade

**Metodologia:**
```
Fase 1 (Idle): 100 alunos → Baseline de desempenho
Fase 2 (Normal): 2000 alunos → Carga esperada
Fase 3 (Peak): 5000 alunos → Pior caso
Fase 4 (Overload): >5000 alunos → Encontrar breaking point
```

**Métricas a Recolher:**
- Throughput (requisições/segundo)
- Latência (P50, P95, P99)
- CPU utilizado (%)
- Memória utilizada (GB)
- I/O de disco (IOPS)
- Taxa de erro (%)

**2. Profiling e Análise Estática**
- Analisar código da aplicação WikiJS
- Identificar operações custosas (queries BD, cálculos)
- Compreender padrão de acesso à memória
- Verificar escalabilidade teórica

**3. Comparação com Aplicações Similares**
- Pesquisar deploimentos conhecidos de WikiJS
- Contactar universidades que usam WikiJS
- Adaptar requisitos para escala da Universidade do Minho

**Recomendação Final:**
Dimensionar para 150-200% da carga máxima esperada (margem de segurança):
- Carga máxima esperada: 5000 alunos
- Recursos estimados: para 7500-10000 alunos
- Razão: Picos imprevistos, crescimento futuro, manutenção

---

## Teste de 07 de Janeiro de 2023

### Pergunta 1: Vantagem e Desafio na Instalação Distribuída

**Pergunta Original:**
"Durante o semestre foram utilizados diferentes componentes de software, tais como o Swap, Ghost, MySQL, e Redis, que podiam ser configurados e instalados seguindo uma arquitetura distribuída. Indique uma vantagem e um desafio a ter em conta quando se pretende seguir uma instalação distribuída para um dado componente de software. Justifique a sua resposta."

**Resposta:**

**Vantagem: Escalabilidade Horizontal e Alta Disponibilidade**

Uma arquitetura distribuída permite:
- Distribuir carga por múltiplos servidores
- Tolerar falhas de servidores individuais
- Crescer de forma praticamente ilimitada

Exemplo prático com MySQL:
- **Arquitetura centralizada**: 1 servidor MySQL com limite de capacidade
- **Arquitetura distribuída**: Múltiplos servidores MySQL com sharding (particionamento por cliente ou por range de dados)
- **Benefício**: Se cliente A tem 1 milhão de registos, esses dados estão num servidor. Cliente B tem seus dados noutro servidor. Sistema escala linearmente com número de clientes.

**Desafio: Consistência de Dados e Sincronização**

Quando dados estão distribuídos, surge o problema:
- **Problema**: Como garantir que todos os servidores têm dados consistentes?
- **Cenário Crítico**: Redis com replicação
  - Master recebe escrita de "score = 100"
  - Master replica para 3 Slaves
  - Se um Slave falha antes de receber a replicação: dado fica inconsistente
  
**Soluções necessárias:**
1. **Replicação Síncrona**: Aguardar confirmação de todos os Slaves (lento)
2. **Replicação Assíncrona**: Não aguardar (rápido mas risco)
3. **Consenso Distribuído**: Usar Raft ou Paxos (complexo)

**Exemplo com Swap distribuído:**
- Frontend web pode estar num servidor
- Backend aplicacional noutro servidor
- BD noutro servidor ainda
- Cache (Redis) noutro servidor
- **Desafio**: Se um falha, todos os pedidos que dependem dele falham

---

### Pergunta 2: Quando Usar Containers vs VMs

**Pergunta Original:**
"Embora ambas sejam consideradas tecnologias de virtualização, máquinas virtuais e containers adequam-se a diferentes tipos de aplicações e serviços. Indique um tipo de aplicação ou serviço onde é mais apropriada a utilização de containers. Justifique a sua resposta."

**Resposta:**

**Aplicações Ideais para Containers: Microserviços Leves com Escalabilidade Rápida**

**Exemplos Concretos:**

1. **APIs Web em Node.js/Python/Go**
   - Stateless
   - Escalabilidade rápida necessária
   - Múltiplas instâncias em paralelo
   - **Porquê containers?** Iniciam em <1 segundo vs VMs em 30+ segundos

2. **Pipeline de Processamento de Dados**
   - Workers que processam filas de mensagens (Kafka, RabbitMQ)
   - Padrão: Spout → Workers → Sink
   - **Porquê containers?** Escalar workers automaticamente com Kubernetes conforme tamanho da fila

3. **Aplicação Web com Cache (ex: Laravel.io)**
   - **Arquitetura**: 
     - 3+ pods de aplicação web (containers)
     - 1 Redis para sessões (container)
     - 1 PostgreSQL (pode ser container ou VM)
   - **Porquê containers?** Replicação rápida de pods web, balanceamento de carga automático

**Por que NÃO usar VMs para estes casos:**

| Aspeto | Containers | VMs |
|--------|-----------|-----|
| **Tempo de arranque** | <1s | 30-60s |
| **Overhead memória** | ~50MB | ~1GB |
| **Densidade** | 100+ por servidor | 5-10 por servidor |
| **Escalabilidade automática** | Fácil (Kubernetes) | Complexa |

**Quando Usar VMs:**

- Aplicações legadas com dependências de SO específicas
- Requisitos de isolamento muito rigorosos
- Aplicações que precisam persistência local de disco

---

### Pergunta 3: Otimização de Armazenamento (Repetida)

**Pergunta Original:**
"Imagine que tem de escolher as melhores configurações para um sistema de armazenamento que tem como principais propósitos garantir alta disponibilidade e simultaneamente reduzir o espaço ocupado pelos dados persistidos. Das funcionalidades tipicamente suportadas por sistemas de armazenamento que estudou, quais é que sugeria? Justifique a sua resposta."

**Resposta:**

[Ver resposta idêntica na Pergunta 3 das 25 Perguntas Integradas - documento anterior]

**Resumo Recomendado:**
1. **Erasure Codes** em vez de Replicação (overhead 1.5x vs 3x)
2. **Compressão** (SNAPPY para balanço CPU/espaço)
3. **Deduplicação** para dados redundantes
4. **Tiering** (SSD hot, HDD warm, Tape cold)

---

### Pergunta 4: Monitorização e Benchmarking com Kubernetes

**Pergunta Original:**

**4.1: "Indique uma das razões pela qual as Kubernetes são frequentemente combinadas com ferramentas de monitorização. Justifique a sua resposta."**

**Resposta 4.1:**

**Razão Principal: Complexidade Dinâmica - Pods Surgem e Desaparecem Constantemente**

Em ambientes Kubernetes:
- Pods são criados/destruídos constantemente (auto-scaling, rolling updates)
- Nós podem falhar a qualquer momento
- Recursos são distribuídos dinamicamente

**Problema sem Monitorização:**
- Ninguém sabe se a aplicação está "saudável"
- Falhas de rede não são detectadas
- Degradação de performance passa despercebida

**Solução: Monitorização Contínua**

Ferramentas como Prometheus + Grafana fornecem:
- **Health Checks**: Confirmar que pods estão vivos
- **Alertas Automáticos**: Se latência > 500ms ou CPU > 80%
- **Visualização em Tempo Real**: Dashboard mostrando estado do cluster
- **Auto-reparação Informada**: Kubernetes sabe quando escalar/parar pods

**Exemplo Prático:**
```
Sem Monitorização:
→ Pod falha silenciosamente
→ Cliente não consegue ligar
→ Problema só descoberto quando reclama

Com Monitorização:
→ Pod falha
→ Prometheus deteta: "Pod down"
→ Alerta dispara: "Pod app-12345 está down"
→ Kubernetes automaticamente cria novo pod
→ Sistema autoreparado em <30 segundos
```

**4.2: "Indique uma vantagem de, ao ambiente com Kubernetes e monitorização, acrescentar também uma ferramenta de avaliação experimental (benchmark). Justifique a sua resposta."**

**Resposta 4.2:**

**Vantagem: Otimização Informada e Predição de Recursos**

Benchmarking fornece dados concretos sobre performance:

1. **Diagnosticar Bottlenecks**
   - Monitorização diz: "Latência está alta"
   - Benchmarking identifica: "É a BD que está lenta, não a aplicação"
   - Ação corretiva baseada em dados

2. **Dimensionamento Correto**
   - Qual é a quantidade certa de CPU/memória por pod?
   - Benchmarking responde com precisão
   - Evita over-provisioning (custo) ou under-provisioning (falhas)

3. **Validar Mudanças**
   - Novo algoritmo proposto é mais rápido?
   - Benchmarking valida antes de deploy em produção

4. **Previsão de Escalabilidade**
   - Com benchmarking: "Este pod suporta 1000 req/s"
   - Com 10000 req/s esperados: necessário 10 pods
   - Kubernetes auto-escala baseado nesta informação

---

## Teste de 12 de Dezembro de 2023

### Pergunta 1: Multi-tenancy em Cloud

**Pergunta Original:**
"A computação em nuvem oferece uma utilização eficiente de recursos de hardware (p.ex., CPU, RAM, disco) através da partilha destes recursos entre múltiplas aplicações (multi-tenancy). Indique uma implicação positiva e uma implicação negativa provenientes desta partilha de recursos. Justifique a sua resposta."

**Resposta:**

**Implicação Positiva: Eficiência e Redução de Custos**

**Mecanismo:**
- Múltiplos tenants (clientes) partilham hardware físico
- Exemplo: Servidor com 8 cores pode alocar:
  - 2 cores para Cliente A
  - 3 cores para Cliente B
  - 3 cores para Cliente C

**Benefício:**
- Cada cliente paga apenas pelo que usa
- Taxa de utilização do servidor: 90%+ (vs 15% em servidores dedicados)
- Redução de custos: 50-70% comparado com infrastructure tradicional

**Exemplo Económico (AWS):**
- VM dedicada (sempre reservada): $500/mês
- Instância shared (pay-as-you-go): $0.10 por hora = ~$70/mês

**Implicação Negativa: Contenção de Recursos e Falta de Isolamento Garantido**

**Problema:**
- Se um tenant usa muita CPU, afeta os outros
- Variabilidade de performance imprevisível

**Cenário Problemático:**
```
Tempo 0:00
- Cliente A usa 2% CPU
- Cliente B usa 2% CPU
- Aplicação de Cliente A rápida: 10ms por pedido

Tempo 0:05
- Cliente A inicia processamento batch pesado
- Cliente A usa 90% CPU
- Sistema operativo faz context-switching entre tenants
- Aplicação de Cliente B agora: 1000ms por pedido (100x mais lenta!)
- Cliente B vê aplicação "muito lenta" sem razão aparente
```

**Soluções Possíveis:**
1. **Quality of Service (QoS)**: Garantir CPU/memória mínima per tenant
2. **Isolamento Forte**: Usar contentores com cgroups restritivos
3. **Tiering**: Servidores dedicados para clientes premium

---

### Pergunta 2: Imagem vs Contentor Docker

**Pergunta Original:**
"O componente Docker Daemon é responsável por gerir imagens, containers e redes num ambiente virtualizado. Indique qual a diferença entre uma imagem e um container na plataforma Docker."

**Resposta:**

**Imagem Docker:**
- Ficheiro imutável (read-only)
- Funciona como um "molde" ou "planta"
- Contém:
  - Sistema base (ex: Ubuntu 20.04)
  - Bibliotecas e dependências (ex: Python 3.9)
  - Código da aplicação
  - Variáveis de ambiente
  - Comandos de inicialização

**Analogia:** Receita de bolo (template)

**Contentor Docker:**
- Instância em execução de uma Imagem
- Tem estado (pode ser modificado durante execução)
- Pode ser criado, reiniciado, parado, removido
- Isolado (filesystem, rede, processos próprios)

**Analogia:** Bolo já cozido (resultado da execução da receita)

**Exemplo Prático:**
```
# Criamos uma IMAGEM (uma vez, reutilizável)
docker build -t minha-app:1.0 .
→ Resultado: ficheiro de imagem (~200MB)

# Criamos 3 CONTENTORES a partir da mesma imagem
docker run -d minha-app:1.0  → Contentor 1
docker run -d minha-app:1.0  → Contentor 2
docker run -d minha-app:1.0  → Contentor 3

→ Resultado: 3 processos independentes, cada um com:
  - Seu próprio sistema de ficheiros
  - Seu próprio IP de rede
  - Seu próprio estado
  
→ Mas todos partilham a mesma IMAGEM base
```

**Diferenças-Chave:**

| Aspeto | Imagem | Contentor |
|--------|--------|----------|
| **Estado** | Imutável | Mutável |
| **Reusabilidade** | Reutilizável | Descartável |
| **Armazenamento** | Ficheiro estático | Memória + camada gravável |
| **Ciclo de vida** | Criada uma vez | Criado e destruído frequentemente |

---

### Pergunta 3: Separação de Dados e Metadados

**Pergunta Original:**
"Em vários sistemas de armazenamento distribuídos, a gestão de dados (i.e., conteúdo) e metadados (p.ex., localização, tamanho, permissões) de ficheiros é feita por componentes diferentes. Ainda, na maioria dos casos, estes componentes são instalados em conjuntos de servidores distintos. Explique a vantagem de considerar componentes independentes para a gestão de dados e metadados. Justifique a sua resposta."

**Resposta:**

[Ver resposta idêntica na Pergunta 10 das 25 Perguntas - documento anterior]

**Resumo:**
1. **Escalabilidade Diferenciada**: Metadados pequenos (RAM), dados volumosos (disco)
2. **Otimização de Recursos**: Metadata servers com RAM/CPU, Data nodes com armazenamento
3. **Transações Atómicas**: Operações de ficheiro centralizadas
4. **Tolerância a Falhas**: Falha de Data Node ≠ perda de metadados

---

### Pergunta 4: Métricas de Benchmarking

**Pergunta Original:**
"Dê dois exemplos de métricas, para além do débito e latência no processamento de pedidos, que possam ser úteis ao avaliar experimentalmente um dado sistema. Justifique a relevância das métricas escolhidas."

**Resposta:**

**Métrica 1: Taxa de Erro (Error Rate)**

**Definição:** Percentagem de pedidos que resultam em erro ou timeout

**Exemplo:**
- 1000 pedidos processados
- 995 sucesso, 5 falharam
- Taxa de erro: 0.5%

**Relevância:**
- Um sistema com latência baixa mas taxa de erro alta é inútil
- Em produção: erro > latência
- Exemplo: Base de dados que responde em 10ms mas falha 50% das vezes = inaceitável

**Aplicação Prática:**
- Avaliar resilência a falhas de rede
- Medir robustez sob sobrecarga
- Validar mecanismos de retry

**Métrica 2: Consumo de Memória (Memory Usage)**

**Definição:** Quantidade de RAM necessária para manter aplicação em execução

**Exemplo:**
- Pod Kubernetes inicializa com 50MB
- Após 1 hora: 200MB
- Após 24 horas: 1.5GB (memory leak!)

**Relevância:**
- Permite dimensionamento correto de recursos
- Detecta memory leaks antes que se tornem críticos
- Influencia número de pods que podem correr num servidor

**Aplicação Prática:**
```
Benchmarking Python web app:
- Memória inicial: 100MB
- Por cada cliente ativo: +5MB
- Para 1000 clientes: 100 + (1000 × 5) = 5.1GB necessário

Decisão: "3 servidores com 2GB cada" é INSUFICIENTE
Necessário: 6-8 servidores ou 1 servidor com 8GB RAM
```

**Alternativas Válidas:**
- Utilização de Disco (IOPS, throughput)
- CPU Utilization (%)
- Escalabilidade Horizontal (aumento de latência com mais carga)
- Footprint de Energia (watts)
- Tempos de GC (Garbage Collection pause)

---

## Teste de 16 de Janeiro de 2024 (Recurso)

### Pergunta 1: Arquitetura BUS

**Pergunta Original:**
"Uma arquitetura distribuída do tipo BUS permite uma maior flexibilidade na comunicação entre diferentes aplicações. Descreva, por suas palavras, em que consiste esta arquitetura e justifique se concorda com a afirmação anterior."

**Resposta:**

**O que é Arquitetura BUS:**

Uma arquitetura BUS é um padrão distribuído onde:
- Um **bus central** (middleware) intermedia toda a comunicação
- Múltiplas aplicações ("produtores" e "consumidores") ligam-se ao bus
- Aplicações não comunicam diretamente entre si, apenas via bus
- Mensagens são encaminhadas segundo regras de routing

**Diagrama:**
```
┌─────────────────────────────────────┐
│      BUS CENTRAL (Message Broker)    │
│  (Kafka, RabbitMQ, Enterprise Service Bus)
└─────────────────────────────────────┘
   ↗           ↑           ↖
  /            |            \
App A      App B      App C     App D
(produz)   (consome)  (produz)  (consome)
```

**Exemplo Prático:**
```
Cenário: Plataforma e-commerce

Sem BUS (Acoplamento Direto):
App Carrinho → App Pagamento
           → App Inventário
           → App Notificações
(4 conexões diretas, quebra se uma app cai)

Com BUS (Desacoplado):
App Carrinho → [BUS: "order.created" event]
App Pagamento ← [Subscreve: "order.created"]
App Inventário ← [Subscreve: "order.created"]
App Notificações ← [Subscreve: "order.created"]
```

**Vantagens (Concordo com a Afirmação):**

1. **Desacoplamento**
   - Aplicações não conhecem umas às outras
   - Mudanças numa app não afetam outras
   - Exemplo: Remover App C não afeta A, B, D

2. **Flexibilidade**
   - Adicionar nova aplicação é trivial
   - Mudar routing de mensagens sem modificar apps
   - Escalabilidade independente de cada app

3. **Resiliência**
   - Se uma app falha, outras continuam
   - Bus pode fazer buffering de mensagens
   - Retry automático de falhas temporárias

4. **Transformação de Mensagens**
   - Bus pode transformar formatos (JSON → XML)
   - Permitir compatibilidade entre versões

**Desvantagens (Ressalvas à Afirmação):**

1. **Complexidade Aumentada**
   - Debugging mais difícil (múltiplos hops)
   - Latência adicional (vs comunicação direta)

2. **Single Point of Failure**
   - Se bus cai, todo o sistema falha
   - Necessário replicar bus para HA

3. **Custo Operacional**
   - Infraestrutura adicional (Kafka, RabbitMQ)
   - Equipa precisa saber gerir bus

**Conclusão:**
Concordo que oferece **maior flexibilidade**, mas a afirmação é parcial. A flexibilidade é conquistada ao custo de complexidade e latência.

---

### Pergunta 2: Roles em Ansible

**Pergunta Original:**
"No guião das aulas práticas dedicado à ferramenta Ansible foram criados diferentes roles para facilitar a instalação automática da aplicação Swap. Qual a função dos roles num playbook Ansible? De que forma os roles contribuem para um melhor aprovisionamento de aplicações? Justifique a sua resposta."

**Resposta:**

[Ver resposta idêntica na Pergunta 14 das 25 Perguntas - documento anterior]

**Resumo:**
- **Função**: Componente reutilizável que encapsula tarefas + configuração
- **Contribuições**: Modularidade, reutilização, composição clara, consistência, escalabilidade

---

### Pergunta 3: Elasticidade e PaaS

**Pergunta Original:**
"Diga o que entende por elasticidade de um serviço a correr num ambiente de computação em nuvem. Em que medida é que uma arquitetura PaaS contribui para a atingir? Justifique a sua resposta."

**Resposta:**

[Ver resposta idêntica na Pergunta 9 das 25 Perguntas - documento anterior]

**Resumo:**
- **Elasticidade**: Aumentar/diminuir recursos automaticamente conforme carga
- **PaaS Contribui**: Abstração, auto-scaling, billing por uso, BD distribuídas

---

### Pergunta 4: Replicação em Kubernetes

**Pergunta Original:**
"Para replicar o servidor aplicacional da aplicação Laravel.io, utilizada no trabalho prático, não basta apenas criar vários pods Kubernetes deste servidor. Indique se concorda com a afirmação anterior, justificando a sua resposta."

**Resposta:**

**Concordo completamente.**

[Ver resposta idêntica na Pergunta 6 das 25 Perguntas - documento anterior]

**Resumo:**
Replicar apenas o servidor web não garante funcionamento:
- BD precisa replicação com sincronização
- Sessões precisam armazenamento distribuído (Redis)
- Uploads precisam filesystem compartilhado
- Caches precisam sincronização

---

## Teste de 10 de Dezembro de 2024

### Pergunta 1: Diferença de Propósitos entre Ansible, VMs e Containers

**Pergunta Original:**
"Tecnologias como Ansible, máquinas virtuais e containers permitem simplificar a gestão de aplicações e serviços. No entanto, a sua utilização está normalmente associada a propósitos distintos. Concorda com esta afirmação? Justifique a sua resposta dando exemplos concretos de cenários de utilizção para cada uma das tecnologias."

**Resposta:**

**Concordo completamente.**

As três tecnologias resolvem problemas **em camadas diferentes da infraestrutura**.

**Máquinas Virtuais (VMs) - Abstração de Hardware**

**Propósito:** Permitir múltiplos SOs e aplicações legacy no mesmo hardware físico

**Cenários Apropriados:**
- Hospedar aplicações Windows e Linux no mesmo servidor
- Executar aplicações antigas com requisitos de SO específicos
- Máxima isolação entre tenants (cloud pública)
- Aplicações que precisam acesso a hardware (GPU, NIC especial)

**Exemplo:** Amazon EC2, Azure VMs

**Containers - Abstração de Dependências**

**Propósito:** Empacotar aplicação com todas as dependências para portabilidade máxima

**Cenários Apropriados:**
- Microserviços que precisam escalar rápido
- Pipelines CI/CD automatizados
- Aplicações stateless que beneficiam de escalabilidade horizontal
- Ambiente "build once, run anywhere"

**Exemplo:** Docker em Kubernetes, contentor Node.js com Redis

**Ansible - Automação de Configuração**

**Propósito:** Definir e aplicar configuração de infraestrutura como código

**Cenários Apropriados:**
- Provisionar VMs com SO + software
- Instalar múltiplas dependências de forma consistente
- Atualizar configuração em 100 servidores simultaneamente
- Gerenciar estado desejado de infraestrutura

**Exemplo:** Provisionar 10 VMs com Nginx, PHP, MySQL automaticamente

**Exemplo Integrado (E-commerce):**

```
1. Criar infraestrutura base (Terraform)
   ↓
2. Provisionar VMs com SO (Ansible)
   ↓
3. Instalar Docker em cada VM (Ansible)
   ↓
4. Lançar containers (Docker + Kubernetes)

Hierarquia:
┌─────────────────────┐
│ Containers (Docker) │  ← Apps escaláveis
│    Orquestração     │
│  (Kubernetes)       │
├─────────────────────┤
│  Automação (Ansible)│  ← Configuração de infra
├─────────────────────┤
│ Virtualização (VMs) │  ← Isolação de hardware
├─────────────────────┤
│   Hardware físico   │
└─────────────────────┘
```

---

### Pergunta 2: Kubernetes para Alta Disponibilidade

**Pergunta Original:**
"Assuma um serviço, composto por uma aplicação web e uma base de dados, que tipicamente é instalado num único servidor (p.ex., Swap, Moonshot). A sua tarefa é dotar este serviço de alta disponibilidade. Discuta que mecanismos da tecnologia Kubernetes podem ajudar nesta tarefa e se esses mecanismos são suficientes, por si só, para obter alta disponibilidade do serviço em questão. Justifique a sua resposta."

**Resposta:**

[Ver resposta idêntica na Pergunta 7 das 25 Perguntas - documento anterior]

**Resumo:**
- **Mecanismos K8s**: Replicação pods, auto-reparação, multi-nó, balanceamento carga
- **Insuficientes para BD**: BD é stateful, precisa replicação + consenso próprio
- **Solução completa**: K8s para web + BD distribuída (PostgreSQL+Patroni) + armazenamento persistente HA

---

### Pergunta 3: Desafios em Armazenamento Cloud vs P2P

**Pergunta Original:**
"As arquiteturas de sistemas de armazenamento adequadas para infraestruturas de computação em nuvem ou ambientes peer-to-peer totalmente descentralizados têm desafios distinctos. Indique dois destes desafios e discuta de que forma os mesmos têm impacto na arquitetura dos sistemas de armazenamento. Justifique a sua resposta."

**Resposta:**

**Desafio 1: Confiabilidade e Tolerância a Falhas**

**Cloud (Centralizado):**
- Hardware é controlado (data center com redundância)
- Falhas são previsíveis (disco falha, ~5% por ano)
- Solução: Replicação ou Erasure Codes

**P2P (Descentralizado):**
- Nós podem sair arbitrariamente (peer offline, internet cai)
- Falhas são impredizíveis e frequentes
- **Impacto na Arquitetura:**
  - Replicação fator muito maior (5-10 em vez de 3)
  - Necessário gossip protocol para disseminação
  - Merkle trees para validação de integridade
  - Exemplo: BitTorrent com 10 peers, qualquer um pode sair

**Desafio 2: Consistência vs Latência**

**Cloud (Confiável):**
- Datacenters com rede de baixa latência (< 1ms entre máquinas)
- Replicação síncrona é viável
- Garantias fortes de consistência

**P2P (Rede Instável):**
- Latência de rede varível (10ms - 1000ms+)
- Replicação síncrona é demasiado lenta
- **Impacto na Arquitetura:**
  - Necessário escolher Eventual Consistency
  - Resolver conflitos de escrita (quem tem razão?)
  - Usar CRDTs (Conflict-free Replicated Data Types)
  - Exemplo: IPFS usa DAG (Directed Acyclic Graph) para permitir múltiplas versões coexistirem

**Comparação:**

| Desafio | Cloud | P2P |
|---------|-------|-----|
| **Replicação Factor** | 3 | 5-10 |
| **Modelo Consistência** | Strong | Eventual |
| **Latência Aceitável** | <100ms | <10s |
| **Overhead Rede** | Baixo | Alto |

---

### Pergunta 4: Monitorização - Impacto na Observação

**Pergunta Original:**
"A errada configuração da camada de observação de um serviço de monitorização pode ter um impacto negativo no desempenho do sistema a ser observado. Concorda com esta afirmação? Justifique a sua resposta dando exemplos concretos de configurações."

**Resposta:**

**Concordo completamente.**

**O Paradoxo do Monitoring: O Monitor Próprio Degradou o Sistema**

**Exemplo 1: Event-Driven Demais (Over-Instrumentation)**

```
Configuração Errada:
- Event handler para CADA operação de disco
- Sistema com 100.000 ops/s
- Monitor gera 100.000 eventos/s
- CPU gasta 50% em logging
- Aplicação só usa 50% CPU

Resultado: Sistema fica 2x mais lento pelo próprio monitoring
```

**Exemplo 2: Retenção de Dados Excessiva**

```
Configuração Errada:
- Guardar 100% dos eventos para sempre
- Em Elasticsearch: 1TB de dados em 24 horas
- Storage full
- Elasticsearch para, sistema desaba

Melhor: Guardar 100% durante 1 dia, 10% durante 7 dias
```

**Exemplo 3: Sampling Rate Inadequado**

```
Configuração Errada (muito frequente):
- Sample CPU a cada 10ms (100 amostras/s)
- Servidor com 1000 processos
- Total: 100.000 samples/s ao Prometheus
- Prometheus sobrecarrega

Configuração Correta:
- Sample a cada 15 segundos (normal)
- Total: ~65 samples/s
- Prometheus confortável
```

**Configurações Recomendadas:**

1. **Amostragem Apropriada**
   - Métrica crítica (latência API): 1 segundo
   - Métrica ordinária (CPU): 15 segundos
   - Métrica rara (erros): event-driven

2. **Retenção Apropriada**
   - Dados detalhados: 7 dias
   - Dados agregados: 1 ano
   - Alertas/logs: 30 dias

3. **Compressão**
   - Comprimir logs antigos
   - Usar formatos eficientes (Protobuf vs JSON)

4. **Cardinality Control**
   - Não criar métricas com labels de alta cardinalidade
   - Exemplo errado: métrica com label "user_id" (milhões de valores)
   - Exemplo correto: métrica com label "region" (dezenas de valores)

---

## Resumo Geral das Perguntas por Teste

| Teste | Data | Tópicos Principais |
|-------|------|------------------|
| 2022-01-12 | Replicação multi-camada, Benchmarking WikiJS |
| 2023-01-07 | Instalação distribuída, Containers vs VMs, Armazenamento, Monitorização K8s |
| 2023-12-12 | Multi-tenancy, Docker, Armazenamento metadados, Benchmarking |
| 2024-01-16 | Arquitetura BUS, Roles Ansible, Elasticidade PaaS, Replicação K8s |
| 2024-12-10 | Ansible/VMs/Containers, K8s HA, Armazenamento Cloud/P2P, Monitorização |

---

**Fim do Documento de Respostas**
**Total: 5 testes × ~4 perguntas = 20 respostas completas**