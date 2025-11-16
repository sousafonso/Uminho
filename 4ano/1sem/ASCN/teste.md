# Aplicações e Serviços de Computação em Nuvem

## Assessment
Projeto (50%) - nota minima de 10
- Checkpoint #1 02/11/2025
- Checkpoint #2 30/11/2025
- Entrega final 29/12/2025
- Apresentação 12-17/01/2026

Teste (50%) - nota minima de 8
- 05/01/2026

---

## Motivação e objetivos
- Sistemas distribuídos visam modularidade e desacoplamento de componentes (storage, database, application server, web server), além de ganhos em performance/escalabilidade e disponibilidade/fiabilidade perante falhas de hardware/software.

---

## Modelo de uma Aplicação Web simples
Presentation Layer + Business / Application Layer + Data Layer

Destaque para a separação de responsabilidades.

---

## Modelo de uma Aplicação Web complexa
Por exemplo,

Presentation Layer + Business / Application Layer + Data Layer + Integration Layer + Security Layer + Management Layer 

No ecossistema Facebook/Meta, o Presto (Presto SQL Engine) separa Coordinator, Workers e clientes, com APIs de Metadata, Data Location e Data Stream, e backends pluggable para diversas fontes de dados.

---

## Desafios
- Deployment: múltiplos componentes com requisitos distintos (hardware, libraries) e heterogeneidade entre HPC e cloud services dificultam automatização e portabilidade.
- Management & Configuration: especificidades por componente e evolução contínua dos “óptimos” tornam a configuração um alvo móvel.
- Monitoring & Benchmarking: é crítico detetar anomalias de performance e falhas em aplicações e infraestruturas complexas com métricas e testes adequados.

---

## Agile e ciclo de entrega
Desenvolvimento iterativo e incremental com feedback contínuo.

Agile development apoia-se em repositórios versionados de source, binaries e documentação para estado inequívoco e “back track”, builds e testes automáticos para feedback rápido, e iterações curtas para reagir a mudanças frequentes e pequenas

No fluxo de Operations tradicional há provisionamento/configuração manual, comunicação informal entre qualificação e produção, com consequências: falta de reprodutibilidade, "[configuration drift](#configuration-drift)" e "[Snowflake servers](#snowflake-servers)", e monitorização subjetiva.

---

## Infrastructure as Code (IaC)
[IaC](#iac) permite gerir e provisionar infraestrutura através de código, promovendo automação, consistência e reprodutibilidade.
[IaC](#iac) propõe provisionamento de hardware/software e configuração via scripts, evitando "wizards" e "control panels", e integrando estes scripts no processo ágil para auditar, versionar e automatizar a infraestrutura.

---

## DevOps
[DevOps](#devops) une desenvolvimento de software (Dev) e operações de TI (Ops) para melhorar colaboração e eficiência na entrega de software.
Práticas [DevOps](#devops) incluem [CI/CD](#cicd), [IaC](#iac), monitorização contínua, e feedback loops para melhorar qualidade e velocidade de entrega.
A junção de Agile + [IaC](#iac) leva a [DevOps](#devops), com processos auto-documentados e versionados (git/JIRA/Artifactory), deployments reprodutíveis e consistentes, servidores descartáveis e suporte a mudanças rápidas e frequentes, alinhando desenvolvimento e operações na cloud (OpenStack, AWS)

## Infrastructure as Code (IaC)
IaC permite gerir e provisionar infraestrutura através de código, promovendo automação, consistência e reprodutibilidade.
IaC propõe provisionamento de hardware/software e configuração via scripts, evitando “wizards” e “control panels”, e integrando estes scripts no processo ágil para auditar, versionar e automatizar a infraestrutura.

---

## Do monólito aos desafios
**Monólito**: aplicação única, difícil de escalar e manter. Num sistema monolítico, múltiplas funcionalidades e dados de vários clientes convivem no mesmo servidor, criando limites de escalabilidade e pontos únicos de falha.

---

## Microserviços
Cada serviço implementa uma funcionalidade específica e escala de forma independente, mas a decomposição é desafiante (“how micro is micro?”), a consistência de dados entre serviços é complexa e os pipelines de deployment/testes tornam-se mais exigentes.

---

## Arquiteturas distribuídas
- **Client-server**: funcionalidade/dados no servidor, com um [stub](#stub) no cliente a expor API e abstrair o protocolo (ex.: HTTP na Web); com um só servidor, não há garantias de escalabilidade/fiabilidade. 
- **Proxy-server**: o proxy torna transparentes múltiplos servidores, facilitando replication/sharding, mas pode ser gargalo e ponto único de falha; exemplo indicado: MongoDB.
- **Manager-worker**: um manager gere metadata (localização), workers servem dados; comum em storage (HDFS, Lustre), melhora scale-out, mas o manager pode ser ponto de contenção/falha.

---

## Padrões Distribuídos 
- **Replication**: múltiplas cópias de dados/funcionalidade para dependability e scale-out de reads, exigindo sincronização entre réplicas. Ou seja, os servidores têm exatamente a mesma informação
- **Partitioning** (sharding horizontal): divide dados por servidores distintos para escalar por conjuntos de clientes/datasets. Servidor A tem informação par ao cliente A e o servidor B tem informação ímpar para o cliente B.
- **Service-orientation** (vertical split, p.ex., microservices): separa serviços por função (storage, database, application), aumentando modularidade e escalabilidade independente. Cada servidor tem o seu serviço específico. Por exemplo, o servidor A é só para storage, o servidor B é só para database e o servidor C é só para application.

---

## Server-group e consenso
Grupos de servidores (server-groups) aumentam disponibilidade e fiabilidade, mas introduzem complexidade na coordenação e consistência de estado entre servidores.
Protocolos de consenso (p.ex., Paxos, Raft) garantem que múltiplos servidores concordem num valor comum, mesmo perante falhas, sendo essenciais para sistemas distribuídos tolerantes a falhas.

- **Server-group**: qualquer servidor atende pedidos; a consistency do estado requer um synchronization protocol entre servidores, removendo single point of failure mas dificultando scale-out pela coordenação; exemplo: Zookeeper.

O trade-off central é entre coordenação para consistência e a escalabilidade horizontal desejada.

---

## Multi-tier
Cada servidor atua como cliente para o tier seguinte. Permite inicialmente escalar cada tier independentemente, mas a coordenação entre tiers é complexa e o desempenho depende do tier mais lento.

**Estado**
Tipicamente: sem estado nas camadas superiores (Web), estado transitório/cache no Application Server e estado persistente na Database, implicando que computação é mais fácil de replicar/shardar do que estado persistente.
A garantia de disponibilidade exige considerar as camadas com estado persistente e os mecanismos de redundância/particionamento adequados.

---

## Provisioning e Deployment
Provisioning é o ato de providenciar recursos (hardware, software, rede) necessários para uma aplicação ou serviço.
Deployment é o ato de disponibilizar um serviço ou aplicação para uso, incluindo instalação, configuração e ativação.

Ambos são críticos em ambientes de cloud computing, onde a automação e a escalabilidade são essenciais.

Pode envolver múltiplos sistemas heterogéneos, exigindo inventário e execução de tarefas sequenciais ou paralelas.

Necessitam de estratégia de gestão de configurações e versionamento para manter a integridade e facilitar mudanças.

---

## Configuration Management
Permite gerir mudanças sistemáticas mantendo integridade ao longo do ciclo de vida.

Configurações são expressas numa linguagem comum e evoluem com a infraestrutura.

Documentação e histórico completo das mudanças são benefícios colaterais.

Automação do processo com unidades de trabalho chamadas recipes.

---

## Recipes
Recipes são scripts que definem o estado desejado de um sistema, incluindo instalação de software, configuração de serviços e gestão de arquivos.

Exemplo de recipe shell script para criar utilizador, instalar pacotes e configurar SSH:
```bash
#!/bin/sh
username=deployer
apt-get -y update
apt-get -y upgrade
apt-get -y install vim-nox openntpd sudo whois aptitude
useradd -G sudo -p "password" -s /bin/bash -m $username
mkdir -p /home/$username/.ssh
chmod 700 /home/$username/.ssh
chown $username: /home/$username/.ssh
echo "public_key" >> /home/$username/.ssh/authorized_keys
chmod 600 /home/$username/.ssh/authorized_keys
chown $username: /home/$username/.ssh/authorized_keys
```

Ferramenta  |  Linguagem   |  Agente  |  Agente-Less  |  SSH
------------|--------------|----------|---------------|-----
Ansible     |  YAML        |  Não     |  Sim          |  Sim
Chef        |  Ruby        |  Sim     |  Suportado    |  Sim
Puppet      |  Puppet DSL  |  Sim     |  Suportado    |  Sim
SaltStack   |  YAML        |  Sim     |  Suportado    |  Sim

---

## Ansible
- Ferramenta, **open-source**, de automação de TI que facilita o provisionamento, configuração e gestão de sistemas.
- Utiliza uma abordagem **agent-less**, **comunicando-se** com os nós geridos **via SSH**.
- As configurações são definidas em arquivos YAML chamados **playbooks**, que descrevem o **estado desejado dos sistemas**.
- Suporta módulos para diversas tarefas, como instalação de pacotes, gestão de serviços e manipulação de arquivos.
- Facilita a orquestração de tarefas complexas em múltiplos sistemas, promovendo consistência e reprodutibilidade.

**How it works**
<img src="Ansible.png" alt="Ansible How It Works" width="400" justify-content="center"/>

- Existe um management node onde escrevemos e executamos os playbooks e os comandos.
- Os hosts onde as tarefas são executadas são definidos no inventory.
- O ansible conecta-se aos hosts via SSH e executa as tarefas definidas nos playbooks utilizando módulos apropriados.

**Vocabulário Ansible**:
- **Playbook**: arquivo YAML que define um conjunto de tarefas a serem executadas em hosts específicos.
- **Inventory**: arquivo que lista os hosts geridos pelo Ansible, podendo ser estático ou dinâmico.
- **Module**: unidade de código que realiza uma tarefa específica, como instalar um pacote ou gerir um serviço.
- **Role**: componente reutilizável com variáveis, templates, tarefas.
- **Task**: ação individual definida num playbook, que utiliza um módulo para realizar uma operação específica. As tarefas só são executadas se a target host corresponder aos critérios definidos no playbook.
- **Handler**: tarefa especial que é executada apenas quando notificada por outra tarefa, geralmente usada para reiniciar serviços após mudanças de configuração.
- **Template**: arquivo que utiliza a linguagem Jinja2 para gerar arquivos de configuração dinâmicos com base em variáveis definidas no playbook ou inventário.

Exemplo simples de playbook Ansible:
```yaml
# provision.yml
- hosts: all
  vars:
    username: someuser
    shell: /bin/bash
  tasks:
    - name: create unprivileged user
      user: # module user
        name: '{{ username }}'
        password: 'secretpasswordhash'
        shell: '{{ shell }}'
    - name: Set SSH authorized_key 
      authorized_key:
        user: '{{ username }}'
        state: present
        key: "{{ lookup('file', '/home/' + someuser + '/.ssh/id_rsa.pub') }}"
```

Exemplo de inventory Ansible:
```ini
# inventory.ini
# hosts.inv
[webservers]
host-[01:99].example.com

[database]
db-01.example.com
staging.example.com
```

Organização de um role Ansible:
```
roles/
  └─ myrole/
     ├─ files/           # ficheiros estáticos
     ├─ templates/       # ficheiros Jinja2 para templates dinâmicos
     ├─ tasks/           # definição de tarefas (main.yml)
     ├─ handlers/        # tarefas especiais a executar após notificação (main.yml)
     ├─ vars/            # variáveis locais da role (main.yml)
     ├─ defaults/        # variáveis por defeito
     └─ meta/            # metadados da role
```

**Handlers (Reações a Notificações)**
Exemplo de handler para reiniciar nginx após mudança de configuração:
```yaml
- name: template configuration file
  template:
    src: template.j2
    dest: /etc/nginx/nginx.conf
  notify:
    - restart nginx

handlers:
  - name: restart nginx
    service:
      name: nginx
      state: restarted
```

**Condições, Loops e Dinamismo**
Suporte a condições para execução condicional de tarefas.
Exemplo de condição:
```yaml
- name: Common Debian
  include_tasks: debian.yml
  when: ansible_os_family == "Debian"

- name: Common RedHat
  include_tasks: rh.yml
  when: ansible_os_family == "RedHat"
```

Loops para instalar múltiplos pacotes ou copiar vários ficheiros:
```yaml
- name: Install Packages
  apt: name="{{ item }}" update_cache=yes state=latest
  loop:
    - vim-nox
    - aptitude

- name: Copy Files
  copy: src="{{ item.source }}" dest="{{ item.destination }}"
  loop:
    - { source: 'motd', destination: '/etc/motd' }
    - { source: 'sshd', destination: '/etc/ssh/sshd_config' }
```

**Facts e Vault**
- **Facts**: são dados recolhidos dos hosts que podem ser usados em testes e templates para personalização.
- **Vault**: permite encriptar dados sensíveis (passwords, chaves) para evitar armazenar em texto plano.

---

## Cloud Services
**Cloud computing, o que é?**
Cloud computing refere-se à **disponibilização de recursos** informáticos (computação, armazenamento, redes, etc.) como serviços on-demand pela internet, com gestão e manutenção por terceiros. O utilizador deixa de precisar de saber como tudo funciona “por baixo” — apenas consome recursos, pagando geralmente conforme o uso, com grande flexibilidade e escalabilidade.

> *“Cloud computing is a specialized form of distributed computing that introduces utilization models for remotely provisioning scalable and measured resources.”*

Estes serviços são divididos em:

- **Infrastructure as a Service (IaaS)**: fornece recursos de infraestrutura virtualizados, como servidores, armazenamento (data centers), redes e VMs. Fornece servidores virtuais, redes, discos, armazenamento, permitindo criar desde raiz qualquer tipo de infraestrutura. O programador/engenheiro controla sistema operativo, middleware, aplicações, mas não o hardware físico (ex: poderes ligar/desligar/deploy VMs, discos, redes virtuais).
- **Platform as a Service (PaaS)**: oferece uma plataforma para desenvolvimento, teste e implantação de aplicações, sem se preocupar com a infraestrutura subjacente. É uma camada acima: oferece ambientes de desenvolvimento, integração, testes e deployment, “escondendo” servidores, patching e escalabilidade ao programador. Usas para criar, publicar e manter apps sem gerir sistemas (ex: upload do código numa plataforma e "magicamente" está online, podes apenas focar-te na lógica da aplicação).
- **Software as a Service (SaaS)**: disponibiliza aplicações através da internet, eliminando a necessidade de instalação e manutenção local. Basicamente são aplicações/software prontas a usar, já completas. Vais diretamente ao produto final. O utilizador só interage com a app, sem preocupação com deployments, armazenamento, permissões, etc. Exemplos incluem plataformas de email como Gmail, colaboração (Google Docs), CRM (Salesforce), bases de dados cloud (DynamoDB) e muito mais.

<img src="Cloud_services.png" alt="Cloud Services" width="600" justify-content="center"/>

---

## Clustering

**Cluster**: conjunto de máquinas (nós) interligadas que trabalham em conjunto para fornecer alta disponibilidade, escalabilidade e desempenho.

> *"A cluster is a group of independent IT resources that are interconnected and work as a single system. System failure rates are reduced while availability and reliability are increased, since redundancy and failover features are inherent to the cluster."*

Um dos requisitos primários a nível de hardware de um cluster é a capacidade de gerir falhas de nós individuais sem afetar a disponibilidade do serviço. Isto é garantido uniformizando os diversos componentes de um hardware, ou seja, tentar ter máquinas idênticas (CPU, RAM, discos, etc.).

---

## OpenStack
OpenStack é uma plataforma de cloud computing open-source que permite criar e gerir infraestruturas de cloud pública e privada.
Fornece um conjunto de serviços para computação, armazenamento e redes virtualizados, permitindo a criação de ambientes de cloud escaláveis e flexíveis.

**Componentes principais do OpenStack**:
- **Nova**: serviço de computação que gere a criação e gestão de máquinas virtuais (VMs, containers).
- **Neutron**: serviço de rede que fornece conectividade de rede para máquinas virtuais.
- **Manila**:  File Sharing (tipo NFS entre VMs).
- **Cinder**: serviço de armazenamento em bloco que permite a criação e gestão de volumes de armazenamento (volumes para VMs).
- **Swift**: serviço de armazenamento de objetos que oferece armazenamento escalável e redundante.
- **Keystone**: serviço de identidade que gere autenticação e autorização para os serviços do OpenStack.
- **Glance**: serviço de imagens que permite armazenar e recuperar imagens de máquinas virtuais.
- **Horizon**: interface web que permite aos utilizadores gerir os recursos do OpenStack.
- **Telemetry**: serviço de monitorização que recolhe métricas e dados de utilização dos recursos.

---

## Automatização, Elasticidade e Conveniência
- **Elasticidade**: 
Capacidade de alocar/recuar recursos conforme a procura (“ilusão” de recursos infinitos). No IaaS, manual ou com scripts. No PaaS/SaaS, a plataforma trata quase tudo: a aplicação escala instâncias de acordo com as necessidades (por exemplo, em PaaS podes aumentar cópias da aplicação facilmente a partir do painel ou automaticamente).

- **Automação e Scalability**: 
Ferramentas de cloud disponibilizam APIs e interfaces para controlar, monitorizar, provisionar e destruir recursos, muitas vezes integradas com pipelines DevOps e sistemas de gestão de configuração (Ansible, Terraform, etc.).

---

## Virtualização
A virtualização representa uma plataforma tecnológica utilizada para a criação de instâncias virtuais de recursos de TI. Em vez de o hardware estar dedicado a um só sistema ou aplicação, **o software de virtualização divide os recursos físicos** — como CPU, memória, armazenamento e rede — em várias “máquinas virtuais” (VMs).

**Benefícios da virtualização:**
- **Melhor utilização do hardware**: Permite que um servidor físico execute várias máquinas virtuais simultaneamente, aproveitando melhor a sua capacidade.

- **Isolamento**: Cada VM está isolada, o que aumenta a segurança e evita que problemas numa VM afetem as outras.

- **Flexibilidade**: É fácil criar, copiar, mover e apagar máquinas virtuais. Por exemplo, um ambiente de testes pode ser criado sem afetar sistemas de produção.

- **Redução de custos**: Menos hardware físico é necessário, diminuindo consumo energético e espaço.

- **Base da cloud computing**: A maior parte das clouds modernas baseia-se em virtualização para fornecer recursos escaláveis e sob demanda.

Tendo várias máquinas num único sistema físico (por ex, um servidor), garantimos que se uma máquina virtual em execução nesse sistema falhar, não vai afetar as outras máquinas virtuais que estão a correr nesse mesmo sistema físico.

---

## Apêndice

1. <a id="snowflake-servers"></a>**Snowflake servers**: servidores únicos, difíceis de gerir e reproduzir.
2. <a id="configuration-drift"></a>**Configuration drift**: deriva de configuração, onde sistemas que deveriam ser idênticos divergem ao longo do tempo devido a mudanças manuais ou inconsistentes.
3. <a id="devops"></a>**DevOps**: cultura e práticas que unem desenvolvimento de software (Dev) e operações de TI (Ops) para melhorar a colaboração e eficiência na entrega de software.
4. <a id="cicd"></a>**CI/CD**: Integração Contínua (CI) e Entrega Contínua (CD) são práticas que automatizam a integração de código e a entrega de software, permitindo lançamentos mais rápidos e frequentes.
5. <a id="iac"></a>**IaC**: Infraestrutura como Código (IaC) é a prática de gerenciar e provisionar infraestrutura de TI através de código, permitindo automação e consistência.
6. <a id="immutable-infrastructure"></a>**Immutable Infrastructure**: Infraestrutura imutável é um modelo onde os servidores são substituídos em vez de atualizados, garantindo consistência e facilidade de rollback.
7. <a id="microservices"></a>**Microservices**: arquitetura de software onde aplicações são compostas por pequenos serviços independentes que se comunicam entre si, facilitando escalabilidade e manutenção.
8. <a id="containers"></a>**Containers**: containers são unidades leves e portáteis que empacotam uma aplicação e suas dependências, permitindo execução consistente em diferentes ambientes.
9. <a id="orquestracao-containers"></a>**Orquestração de Containers**: orquestração de containers é o processo de gerenciar a implantação, escalabilidade e operação de containers, frequentemente utilizando ferramentas como Kubernetes.
10. <a id="serverless-computing"></a>**Serverless Computing**: computação sem servidor é um modelo onde o provedor de nuvem gerencia a infraestrutura, permitindo que os desenvolvedores se concentrem no código sem se preocupar com servidores.
11. <a id="cloud-native"></a>**Cloud Native**: aplicações nativas da nuvem são projetadas para aproveitar ao máximo os serviços e características da computação em nuvem, como escalabilidade e resiliência.
12. <a id="stub"></a>**Stub**: um stub é um objeto que simula o comportamento de um componente real em um sistema, permitindo testes e desenvolvimento sem depender da implementação completa do componente.
13. <a id="consensus-protocols"></a>**Bus**: um barramento é um sistema de comunicação que permite que diferentes partes de um sistema distribuído se comuniquem entre si, facilitando a troca de mensagens e dados. Garante flexibilidade e escalabilidade.
14. <a id="consensus-protocols"></a>**Kafka**: Kafka é uma plataforma de streaming distribuída que permite a publicação, assinatura, armazenamento e processamento de fluxos de dados em tempo real.
15. <a id="consensus-protocols"></a>**Provisioning**: Ato de providenciar recursos.
16. <a id="consensus-protocols"></a>**Deployment**: Ato de disponibilizar um serviço ou aplicação.
17. <a id="cloud"></a>**Cloud**: ambiente de TI distinto concebido para o provisionamento remoto de recursos de TI escaláveis e mensurados
