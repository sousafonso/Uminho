
# Aplicações e Serviços de Computação em Nuvem

_Notas de aula — ASCN · 4.º ano, 1.º semestre_

---

## Sumário rápido

- Assessment
- Motivação & objetivos
- Modelos de aplicação (simples → complexa)
- Desafios, Agile e DevOps
- IaC, Configuration Management e Recipes (Ex.: Ansible)
- Cloud services (IaaS / PaaS / SaaS) e OpenStack
- Conceitos: elasticidade, automação, microserviços, consenso
- Virtualização (hipervisores, time-slicing)  
- Apêndice (termos e definições)

---

## Assessment

- Projeto — 50% (nota mínima: 10)
  - Checkpoint #1: 02/11/2025
  - Checkpoint #2: 30/11/2025
  - Entrega final: 29/12/2025
  - Apresentação: 12–17/01/2026

- Teste — 50% (nota mínima: 8)
  - Data: 05/01/2026

---

## Motivação e objetivos

Os sistemas distribuídos procuram modularidade e desacoplamento (storage, database, application server, web server). Os ganhos principais são:

- Performance e escalabilidade
- Disponibilidade e fiabilidade perante falhas de hardware/software

Separar responsabilidades facilita manutenção, testes e evolução.

---

## Modelos de Aplicação

### Aplicação Web simples

Presentation Layer → Business/Application Layer → Data Layer

Destaque: separação clara de responsabilidades.

### Aplicação Web complexa

Presentation Layer + Business/Application Layer + Data Layer + Integration Layer + Security Layer + Management Layer

Exemplo (ecossistema Facebook/Meta): o Presto separa coordinator, workers e clientes, com APIs de metadata, localização de dados e streams; os backends são pluggable para várias fontes.

---

## Desafios comuns

- Deployment: múltiplos componentes com requisitos distintos e heterogeneidade entre ambientes (HPC vs cloud) complicam automatização e portabilidade.
- Management & Configuration: cada componente tem especificidades e as “melhores” configurações mudam com o tempo.
- Monitoring & Benchmarking: detecção de anomalias e regressões de performance é crítica em infraestruturas complexas.

---

## Agile, ciclo de entrega e operações

Agile promove iterações curtas e feedback contínuo. Boas práticas incluem:

- Repositórios versionados (código, binários, documentação)
- Builds e testes automáticos para feedback rápido
- Iterações curtas para reagir a mudanças

No fluxo Operations tradicional encontramos: provisionamento/configuração manual e comunicação informal entre qualificação e produção — o que causa falta de reprodutibilidade, configuration drift e os chamados "snowflake servers".

---

## Infrastructure as Code (IaC)

IaC permite gerir e provisionar infraestrutura via código: automação, consistência e reprodutibilidade.

- Integra-se com processos ágeis para auditar e versionar infraestrutura
- Evita “wizards” e operações manuais repetitivas

---

## DevOps

DevOps junta Development (Dev) e Operations (Ops) para melhorar colaboração e velocidade de entrega.
Práticas comuns: CI/CD, IaC, monitorização contínua e feedback loops.

Combinar Agile + IaC traz deployments reprodutíveis, servidores descartáveis e processos auto-documentados (git, JIRA, Artifactory). Exemplos de cloud: OpenStack, AWS.

---

## Do monólito aos microserviços

**Monólito**: aplicação única, centralizada — mais simples de começar, mais difícil de escalar e manter a longo prazo.

**Microserviços**: cada serviço é responsável por uma funcionalidade e escala independentemente. Vantagens: modularidade e escalabilidade. Desafios: decomposição, consistência de dados e pipelines de deployment/testes mais complexos.

---

## Arquiteturas distribuídas (padrões)

- Client–server: API no cliente (stub) abstrai o protocolo; com um único servidor não há garantias de escala/fiabilidade.
- Proxy–server: o proxy distribui carga e possibilita replication/sharding; pode também ser um gargalo.
- Manager–worker: manager gere metadados; workers servem dados (comum em HDFS, Lustre).

Padrões:

- Replication — múltiplas cópias para disponibilidade e scale-out de reads (exigem sincronização)
- Partitioning / Sharding — dividir dados entre servidores para escalar horizontalmente
- Service-orientation — separar por função (storage, database, application)

---

## Server-group e protocolos de consenso

Server-groups melhoram disponibilidade mas exigem coordenação (ex.: Zookeeper). Protocolos como Paxos e Raft garantem acordo entre servidores mesmo perante falhas.

Trade-off: consistência vs. escalabilidade.

---

## Multi-tier e estado

Cada tier consome o serviço do tier seguinte. É comum ter:

- Camadas superiores geralmente sem estado (stateless)
- Application servers com estado transitório/cache
- Databases com estado persistente

Computação é mais simples de replicar que estado persistente — é preciso desenhar redundância e particionamento para garantir disponibilidade.

---

## Provisioning & Deployment

- Provisioning: preparar recursos (hardware, software, rede)
- Deployment: disponibilizar e ativar a aplicação/serviço

Ambos exigem automação, inventário, estratégia de configuração e versionamento para manter integridade e facilidade de mudanças.

---

## Configuration Management & Recipes

Configuration management organiza mudanças e mantém integridade. Recipes são scripts que descrevem o estado desejado (instalação, configuração, serviços).

Exemplo (recipe shell):

```bash
#!/bin/sh
username=deployer
apt-get -y update && apt-get -y upgrade
apt-get -y install vim-nox openntpd sudo whois aptitude
useradd -G sudo -p "password" -s /bin/bash -m $username
mkdir -p /home/$username/.ssh && chmod 700 /home/$username/.ssh
chown $username: /home/$username/.ssh
echo "public_key" >> /home/$username/.ssh/authorized_keys
chmod 600 /home/$username/.ssh/authorized_keys
chown $username: /home/$username/.ssh/authorized_keys
```

Ferramentas populares:

| Ferramenta  | Linguagem    | Agente | Agent-less | SSH |
|-------------|--------------|--------|------------|-----|
| Ansible     | YAML         | Não    | Sim        | Sim |
| Chef        | Ruby         | Sim    | Suportado  | Sim |
| Puppet      | Puppet DSL   | Sim    | Suportado  | Sim |
| SaltStack   | YAML         | Sim    | Suportado  | Sim |

---

## Ansible (resumo)

- Open-source, agent-less (SSH)
- Configurações em playbooks (YAML)
- Módulos para tarefas: instalar pacotes, gerir serviços, manipular ficheiros
- Roles, templates (Jinja2), handlers e facts são conceitos-chave

Exemplo simples de playbook:

```yaml
- hosts: all
  vars:
    username: someuser
    shell: /bin/bash
  tasks:
    - name: create unprivileged user
      user:
        name: '{{ username }}'
        password: 'secretpasswordhash'
        shell: '{{ shell }}'
    - name: Set SSH authorized_key
      authorized_key:
        user: '{{ username }}'
        state: present
        key: "{{ lookup('file', '/home/' + someuser + '/.ssh/id_rsa.pub') }}"
```

---

## Cloud Services (IaaS / PaaS / SaaS)

Cloud computing refere-se à **disponibilização de recursos** informáticos (computação, armazenamento, redes, etc.) como serviços on-demand pela internet, com gestão e manutenção por terceiros. O utilizador deixa de precisar de saber como tudo funciona “por baixo” — apenas consome recursos, pagando geralmente conforme o uso, com grande flexibilidade e escalabilidade.

- IaaS: recursos virtuais (VMs, redes, discos). O utilizador controla SO e aplicações.
- PaaS: plataforma para desenvolvimento & deployment — o utilizador foca-se na aplicação.
- SaaS: aplicações prontas para uso (ex.: Gmail, Google Docs, Salesforce).

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

## Elasticidade, automação e conveniência

- Elasticidade: alocar/libertar recursos conforme procura
- Automação: APIs e ferramentas (Terraform, Ansible) para controlar o ciclo de vida

Integração com pipelines DevOps permite CI/CD e operações automatizadas.

---
## Virtualização

Criação de máquinas virtuais (VMs) que abstraem hardware físico, permitindo múltiplos SOs num único host. Em vez de o hardware estar dedicado a um só sistema ou aplicação, o software de virtualização divide os recursos físicos — como CPU, memória, armazenamento e rede — em várias “máquinas virtuais” (VMs).
Antes do surgimento das tecnologias de virtualização, o software estava limitado a residir e estar acoplado a ambientes de hardware estáticos


**Vantagens**:
- Isolamento: falhas numa VM não afetam outras
- Segurança: Não queremos que um utilizador de uma VM A aceda aos recursos de uma VM B.
- Eficiência: melhor utilização de recursos físicos. Mas a VM A não pode comprometer a performance de uma VM B.
- Flexibilidade: fácil criação, destruição e migração de VMs
- Testes e desenvolvimento: ambientes isolados para testes

**Desvantagens**:
- Overhead: desempenho inferior ao nativo
- Over provisioning: risco de alocar mais recursos do que o disponível (saturação dos recursos físicos)

> "when multiple VMs, running in the same server, require more than the
available amount of CPU cores, memory, disk/network bandwidth"

- Complexidade: gestão adicional
- Segurança: novas superfícies de ataque
- Isolação: Um utilizador não pode ter acesso aos recursos físicos do servidor.
- Dependência: A falha de um recurso físico pode comprometer várias VMs.

<img src="virtualizacao.png" alt="Virtualization layers" style="width:500px;"/>

**Definição de Hipervisor (Virtual Machine Monitor - VMM)**: software que cria e gere VMs, abstraindo o hardware físico (ex.: VMware ESXi, Microsoft Hyper-V, Xen, VirtualBox). É uma espécie de interface / abstração que permite a interação entre as máquinas virtuais e o Sistema Operativo nativo e o respetivo hardware.

**Time-slicing**: técnica de partilha de CPU entre múltiplas VMs, onde cada VM recebe uma fatia de tempo para executar as suas tarefas.

---
## Containers
Containers são unidades **leves** e **portáteis** que empacotam uma aplicação e suas dependências, permitindo execução consistente em diferentes ambientes. Ao contrário das VMs, os containers partilham o mesmo kernel do SO hospedeiro, tornando-os mais eficientes em termos de recursos.

Um container, no contexto de computação, é como uma "caixa" virtual que guarda tudo o que uma aplicação precisa para funcionar: o código, as bibliotecas, arquivos de configuração e dependências necessárias. Imagine literalmente uma caixa de transporte (como as usadas em navios): você coloca a mercadoria dentro, fecha, e pode levar para qualquer lugar sem se preocupar se lá tem espaço, luz ou outras condições, porque tudo necessário já está dentro da caixa. São **ambientes isolados** que tornam aplicações **independentes do sistema onde estão**, facilitando o transporte e execução.

**Engines** de containers (ex.: Docker, Podman) gerem a criação, execução e gestão de containers. Os containers partilham o hardware e o SO com o host.

**Types de containers**:
- OS Containers: executam diversos processos e simulam um SO leve (LXC)
- Application Containers: focados no deployment de uma aplicação/processo (Docker). Aqui cada aplicação é vista como um único processo.

### Building blocks dos containers:
- Namespaces: isolam recursos do sistema (processos, rede, etc.) para cada container.
- Control groups: controlam e limitam o uso de recursos (CPU, memória) por container. Alocação de cursos por processos.
- SELinux/AppArmor: fornecem segurança adicional através de políticas de acesso para que um container não interfira no SO e outros containers.

---
## DOCKER
### Componentes
- Docker daemon: serviço que gere containers, imagens, redes e volumes.
- Docker CLI: interface de linha de comandos para interagir com o daemon.
- Docker Objects: 
  - Imagens: templates imutáveis para criar containers. Ficheiros que contêm o código e bibliotecas necessárias para executar uma aplicação.
  - Containers: instâncias em execução de imagens.
- Volumes: armazenamento persistente para containers. Ou seja, ao eliminar um container, os dados armazenados num volume permanecem intactos.
- Networks: permitem comunicação entre containers e com o exterior. O container é visto como mais um nó na rede.
---
## KUBERNETES
Kubernetes é uma plataforma open-source para orquestração de containers, que automatiza a implantação, escalabilidade e gestão de aplicações em containers.

Features interessantes:
- Network management: cada pod recebe um IP único, facilitando a comunicação.
- Modular Service Orchestration: permite definir serviços, deployments e políticas de escalabilidade.
- Self-healing: reinicia containers falhados, substitui e reprograma containers quando os nós falham.
- Scaling: ajusta automaticamente o número de réplicas de containers comforme a procura.
- Storage orchestration: monta automaticamente sistemas de armazenamento, como volumes locais ou serviços de cloud.
- Automated rollouts and rollbacks: atualiza aplicações sem tempo de inatividade e reverte para versões anteriores se necessário.

### Componentes principais:
- Control Plane: gere o estado do cluster (API server, scheduler, controller manager).
  - API Server: interface principal para interagir com o cluster.
  - etcd: base de dados chave-valor que armazena o estado do cluster.
  - Scheduler: atribui pods a nós com base em recursos disponíveis.
  - Controller Manager: gere controladores que mantêm o estado desejado do cluster.
- Nodes: máquinas que executam containers (kubelet, kube-proxy).
  - Kubelet: agente que corre em cada nó, garantindo que os containers estão a correr conforme especificado.
  - Kube-proxy: gere a rede para os pods, permitindo comunicação dentro e fora do cluster.

### K8s Cluster
É um grupo de máquinas (físicas ou virtuais) que executam aplicações em containers geridas pelo Kubernetes. Consiste em um Control Plane e vários Nodes.

---

## Apêndice — termos e definições

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

---

_Fim — notas organizadas para estudo e referência rápida._
