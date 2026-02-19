# Guia Completo: Programação de Agentes em Python

## Manual Técnico e Padrões Base para Desenvolvimento de Sistemas Multi-Agente

---

## 📚 Índice

1. [Introdução aos Agentes](#introdução-aos-agentes)
2. [Arquitetura Base de um Agente](#arquitetura-base-de-um-agente)
3. [Padrões Universais de Agentes](#padrões-universais-de-agentes)
4. [Framework SPADE](#framework-spade)
5. [Serialização com jsonpickle](#serialização-com-jsonpickle)
6. [Comunicação entre Agentes](#comunicação-entre-agentes)
7. [Padrões de Comportamento](#padrões-de-comportamento)
8. [Exemplos Práticos Completos](#exemplos-práticos-completos)
9. [Boas Práticas](#boas-práticas)

---

## Introdução aos Agentes

### O que é um Agente?

Um **agente** é uma entidade computacional autónoma que:

- **Percebe** o ambiente através de sensores
- **Age** no ambiente através de atuadores
- Opera de forma **autónoma** (sem intervenção humana direta)
- Possui **objetivos** ou funções de utilidade
- Pode **comunicar** com outros agentes
- Pode **aprender** e adaptar-se ao ambiente

### Propriedades Fundamentais

| Propriedade | Descrição |
|-------------|-----------|
| **Autonomia** | Opera sem intervenção direta |
| **Reatividade** | Responde a mudanças no ambiente |
| **Proatividade** | Toma iniciativa para atingir objetivos |
| **Sociabilidade** | Comunica com outros agentes |
| **Mobilidade** | Pode migrar entre plataformas (opcional) |
| **Racionalidade** | Age para maximizar objetivos |

---

## Arquitetura Base de um Agente

### Modelo Conceptual

```
┌─────────────────────────────────────────┐
│            AGENTE                       │
│                                         │
│  ┌─────────────────────────────────┐   │
│  │   PERCEÇÃO (Sensores)           │   │
│  └──────────────┬──────────────────┘   │
│                 │                       │
│                 ▼                       │
│  ┌─────────────────────────────────┐   │
│  │   ESTADO INTERNO                │   │
│  │   - Crenças (Beliefs)           │   │
│  │   - Objetivos (Goals)           │   │
│  │   - Conhecimento                │   │
│  └──────────────┬──────────────────┘   │
│                 │                       │
│                 ▼                       │
│  ┌─────────────────────────────────┐   │
│  │   RACIOCÍNIO (Reasoning)        │   │
│  │   - Planeamento                 │   │
│  │   - Tomada de Decisão           │   │
│  └──────────────┬──────────────────┘   │
│                 │                       │
│                 ▼                       │
│  ┌─────────────────────────────────┐   │
│  │   AÇÃO (Atuadores)              │   │
│  └─────────────────────────────────┘   │
│                                         │
└─────────────────────────────────────────┘
         ▲                      │
         │                      ▼
    ┌─────────────────────────────────┐
    │       AMBIENTE                   │
    └─────────────────────────────────┘
```

### Componentes Essenciais

#### 1. Perceção
- Recebe informação do ambiente
- Processa mensagens de outros agentes
- Atualiza estado interno

#### 2. Estado Interno
- **Beliefs**: Conhecimento sobre o mundo
- **Desires**: Objetivos desejados
- **Intentions**: Planos comprometidos

#### 3. Raciocínio
- Avalia estado atual
- Gera planos de ação
- Seleciona ações apropriadas

#### 4. Ação
- Executa operações
- Envia mensagens
- Modifica o ambiente

---

## Padrões Universais de Agentes

### Padrão 1: Estrutura Base Universal

```python
class AgentBase:
    """
    Padrão universal para todos os agentes
    """
    def __init__(self, agent_id, environment=None):
        # Identificação
        self.agent_id = agent_id
        self.environment = environment
        
        # Estado interno
        self.beliefs = {}  # Crenças sobre o mundo
        self.goals = []    # Objetivos a atingir
        self.plans = []    # Planos de ação
        
        # Comunicação
        self.inbox = []    # Mensagens recebidas
        self.outbox = []   # Mensagens a enviar
        
        # Estado operacional
        self.is_running = False
        self.memory = {}   # Memória persistente
    
    def perceive(self):
        """
        PROCEDIMENTO BASE 1: PERCEÇÃO
        Recolhe informação do ambiente e de mensagens
        """
        # Ler mensagens
        self.process_messages()
        
        # Ler sensores do ambiente
        if self.environment:
            self.update_beliefs_from_environment()
    
    def reason(self):
        """
        PROCEDIMENTO BASE 2: RACIOCÍNIO
        Analisa estado e decide próxima ação
        """
        # Avaliar crenças atuais
        self.evaluate_beliefs()
        
        # Selecionar objetivos prioritários
        active_goals = self.select_goals()
        
        # Gerar planos para objetivos
        self.generate_plans(active_goals)
        
        # Escolher melhor plano
        selected_plan = self.select_best_plan()
        
        return selected_plan
    
    def act(self, plan):
        """
        PROCEDIMENTO BASE 3: AÇÃO
        Executa o plano selecionado
        """
        if plan:
            # Executar ações do plano
            for action in plan.actions:
                self.execute_action(action)
            
            # Enviar mensagens preparadas
            self.send_messages()
    
    def run(self):
        """
        PROCEDIMENTO BASE 4: LOOP PRINCIPAL
        Ciclo perceção-raciocínio-ação
        """
        self.is_running = True
        
        while self.is_running:
            # Ciclo BDI (Belief-Desire-Intention)
            self.perceive()        # Atualizar crenças
            plan = self.reason()   # Decidir o que fazer
            self.act(plan)         # Executar ação
            
            # Verificar condição de paragem
            if self.should_stop():
                self.is_running = False
    
    # ============================================
    # MÉTODOS AUXILIARES (implementar conforme necessário)
    # ============================================
    
    def process_messages(self):
        """Processar mensagens recebidas"""
        for message in self.inbox:
            self.handle_message(message)
        self.inbox.clear()
    
    def handle_message(self, message):
        """Tratar uma mensagem específica"""
        # Implementar lógica específica
        pass
    
    def update_beliefs_from_environment(self):
        """Atualizar crenças baseado no ambiente"""
        pass
    
    def evaluate_beliefs(self):
        """Avaliar estado das crenças"""
        pass
    
    def select_goals(self):
        """Selecionar objetivos ativos"""
        return self.goals
    
    def generate_plans(self, goals):
        """Gerar planos para objetivos"""
        pass
    
    def select_best_plan(self):
        """Escolher melhor plano"""
        if self.plans:
            return self.plans[0]
        return None
    
    def execute_action(self, action):
        """Executar uma ação específica"""
        pass
    
    def send_messages(self):
        """Enviar mensagens preparadas"""
        for message in self.outbox:
            if self.environment:
                self.environment.deliver_message(message)
        self.outbox.clear()
    
    def should_stop(self):
        """Verificar se deve parar"""
        return not self.is_running
    
    def stop(self):
        """Parar o agente"""
        self.is_running = False
```

### Padrão 2: Agente Reativo

```python
class ReactiveAgent(AgentBase):
    """
    Agente que reage diretamente a estímulos
    Padrão: Condição → Ação
    """
    def __init__(self, agent_id):
        super().__init__(agent_id)
        self.rules = []  # Lista de regras (condição, ação)
    
    def add_rule(self, condition, action):
        """Adicionar regra condição → ação"""
        self.rules.append((condition, action))
    
    def reason(self):
        """Raciocínio reativo: verifica regras"""
        for condition, action in self.rules:
            if condition(self):
                return action
        return None
    
    def act(self, action):
        """Executa ação diretamente"""
        if action:
            action(self)

# Exemplo de uso:
agent = ReactiveAgent("reactive_1")

# Definir regras
agent.add_rule(
    condition=lambda a: a.beliefs.get("temperature") > 30,
    action=lambda a: print("Ligar ar condicionado")
)

agent.add_rule(
    condition=lambda a: a.beliefs.get("temperature") < 15,
    action=lambda a: print("Ligar aquecimento")
)
```

### Padrão 3: Agente Deliberativo (BDI)

```python
class BDIAgent(AgentBase):
    """
    Agente BDI (Belief-Desire-Intention)
    Possui raciocínio complexo e planeamento
    """
    def __init__(self, agent_id):
        super().__init__(agent_id)
        self.desires = []      # Desejos (objetivos potenciais)
        self.intentions = []   # Intenções (objetivos comprometidos)
    
    def reason(self):
        """Raciocínio BDI completo"""
        # 1. Atualizar beliefs baseado em perceções
        self.update_beliefs()
        
        # 2. Gerar opções (desires) baseado em beliefs
        self.generate_desires()
        
        # 3. Filtrar desires para formar intentions
        self.deliberate()
        
        # 4. Planear ações para intentions
        plan = self.plan()
        
        return plan
    
    def update_beliefs(self):
        """Atualizar modelo do mundo"""
        # Incorporar novas informações
        pass
    
    def generate_desires(self):
        """Gerar objetivos possíveis"""
        # Baseado em beliefs, que objetivos são viáveis?
        pass
    
    def deliberate(self):
        """Escolher quais desires comprometer (intentions)"""
        # Priorizar desires e comprometer recursos
        self.intentions = self.desires[:3]  # Exemplo: top 3
    
    def plan(self):
        """Gerar plano para intentions"""
        # Criar sequência de ações
        if self.intentions:
            return self.create_plan_for(self.intentions[0])
        return None
    
    def create_plan_for(self, intention):
        """Criar plano específico para uma intenção"""
        # Implementar algoritmo de planeamento
        pass
```

### Padrão 4: Agente Comunicativo

```python
class CommunicativeAgent(AgentBase):
    """
    Agente focado em comunicação com outros agentes
    Implementa protocolos de conversação
    """
    def __init__(self, agent_id):
        super().__init__(agent_id)
        self.conversations = {}  # Conversações ativas
        self.protocols = {}      # Protocolos suportados
    
    def send_message(self, receiver, performative, content):
        """Enviar mensagem com ACL"""
        message = {
            "sender": self.agent_id,
            "receiver": receiver,
            "performative": performative,
            "content": content,
            "conversation_id": self.generate_conversation_id()
        }
        self.outbox.append(message)
    
    def handle_message(self, message):
        """Tratar mensagem baseado em performative"""
        performative = message.get("performative")
        
        handlers = {
            "REQUEST": self.handle_request,
            "INFORM": self.handle_inform,
            "QUERY": self.handle_query,
            "AGREE": self.handle_agree,
            "REFUSE": self.handle_refuse,
        }
        
        handler = handlers.get(performative)
        if handler:
            handler(message)
    
    def handle_request(self, message):
        """Tratar pedido"""
        # Avaliar se pode satisfazer
        if self.can_satisfy(message["content"]):
            self.send_message(
                message["sender"],
                "AGREE",
                "Request accepted"
            )
        else:
            self.send_message(
                message["sender"],
                "REFUSE",
                "Cannot satisfy request"
            )
    
    def handle_inform(self, message):
        """Tratar informação recebida"""
        # Atualizar beliefs
        self.beliefs.update(message["content"])
    
    def handle_query(self, message):
        """Responder a consulta"""
        # Enviar informação solicitada
        pass
    
    def handle_agree(self, message):
        """Processar concordância"""
        pass
    
    def handle_refuse(self, message):
        """Processar recusa"""
        pass
    
    def generate_conversation_id(self):
        """Gerar ID único para conversação"""
        import uuid
        return str(uuid.uuid4())
```

---

## Framework SPADE

### Instalação e Configuração

```bash
# Instalar SPADE
pip install spade

# Instalar dependências
pip install jsonpickle
pip install aioxmpp
```

### Anatomia de um Agente SPADE

```python
import spade
from spade.agent import Agent
from spade.behaviour import CyclicBehaviour, OneShotBehaviour, PeriodicBehaviour
from spade.message import Message
from spade.template import Template

class MyAgent(Agent):
    """
    Estrutura universal de um agente SPADE
    """
    
    # ============================================
    # 1. INICIALIZAÇÃO
    # ============================================
    def __init__(self, jid, password, *args, **kwargs):
        super().__init__(jid, password)
        # Inicializar atributos personalizados
        self.custom_data = {}
        self.state = "initialized"
    
    # ============================================
    # 2. SETUP - CONFIGURAÇÃO INICIAL
    # ============================================
    async def setup(self):
        """
        Método chamado automaticamente quando agente inicia
        Use para:
        - Inicializar variáveis
        - Adicionar comportamentos
        - Configurar templates
        """
        print(f"Agente {self.jid} iniciado")
        
        # Adicionar comportamentos
        self.add_behaviour(self.MyBehaviour())
        
        # Comportamento com template (filtro de mensagens)
        template = Template()
        template.set_metadata("performative", "request")
        self.add_behaviour(self.RequestHandler(), template)
    
    # ============================================
    # 3. COMPORTAMENTOS (BEHAVIOURS)
    # ============================================
    
    class MyBehaviour(CyclicBehaviour):
        """
        Comportamento cíclico - executa continuamente
        """
        async def run(self):
            """Método executado em loop"""
            print(f"Comportamento a executar...")
            await asyncio.sleep(1)
    
    class RequestHandler(CyclicBehaviour):
        """
        Comportamento para tratar pedidos
        """
        async def run(self):
            # Receber mensagem (timeout em segundos)
            msg = await self.receive(timeout=10)
            
            if msg:
                print(f"Mensagem recebida: {msg.body}")
                
                # Processar mensagem
                await self.process_request(msg)
        
        async def process_request(self, msg):
            """Processar pedido específico"""
            # Criar resposta
            reply = msg.make_reply()
            reply.set_metadata("performative", "agree")
            reply.body = "Pedido aceite"
            
            # Enviar resposta
            await self.send(reply)
    
    # ============================================
    # 4. MÉTODOS AUXILIARES
    # ============================================
    
    async def send_message_to(self, receiver_jid, performative, content):
        """Método auxiliar para enviar mensagens"""
        msg = Message(to=receiver_jid)
        msg.set_metadata("performative", performative)
        msg.body = content
        
        # Enviar através de um comportamento
        await self.send(msg)
```

### Tipos de Comportamentos SPADE

#### 1. OneShotBehaviour - Executa Uma Vez

```python
class OneShotExample(OneShotBehaviour):
    """Executa uma única vez e termina"""
    async def run(self):
        print("Executando tarefa única")
        # Fazer algo uma vez
        await self.agent.stop()
```

#### 2. CyclicBehaviour - Loop Infinito

```python
class CyclicExample(CyclicBehaviour):
    """Executa continuamente até ser parado"""
    async def run(self):
        msg = await self.receive(timeout=5)
        if msg:
            print(f"Recebida: {msg.body}")
        else:
            print("Sem mensagens")
```

#### 3. PeriodicBehaviour - Execução Periódica

```python
class PeriodicExample(PeriodicBehaviour):
    """Executa a cada X segundos"""
    async def run(self):
        print(f"Execução periódica às {datetime.now()}")
    
    async def on_start(self):
        print("Comportamento periódico iniciado")
    
    async def on_end(self):
        print("Comportamento periódico terminado")

# Usar com período de 5 segundos
agent.add_behaviour(PeriodicExample(period=5))
```

#### 4. TimeoutBehaviour - Executa Após Timeout

```python
from spade.behaviour import TimeoutBehaviour

class TimeoutExample(TimeoutBehaviour):
    """Executa após X segundos"""
    async def run(self):
        print("Timeout atingido!")

# Executar após 10 segundos
agent.add_behaviour(TimeoutExample(start_at=datetime.now() + timedelta(seconds=10)))
```

#### 5. FSMBehaviour - Máquina de Estados Finitos

```python
from spade.behaviour import FSMBehaviour, State

STATE_ONE = "STATE_ONE"
STATE_TWO = "STATE_TWO"
STATE_THREE = "STATE_THREE"

class StateOne(State):
    async def run(self):
        print("Estado 1")
        self.set_next_state(STATE_TWO)

class StateTwo(State):
    async def run(self):
        print("Estado 2")
        # Condição para próximo estado
        if self.agent.condition:
            self.set_next_state(STATE_THREE)
        else:
            self.set_next_state(STATE_ONE)

class StateThree(State):
    async def run(self):
        print("Estado 3 (final)")
        # Não define próximo estado = estado final

class MyFSM(FSMBehaviour):
    async def on_start(self):
        print(f"FSM iniciada no estado {self.current_state}")
    
    async def on_end(self):
        print("FSM terminada")

# Configurar FSM
fsm = MyFSM()
fsm.add_state(name=STATE_ONE, state=StateOne(), initial=True)
fsm.add_state(name=STATE_TWO, state=StateTwo())
fsm.add_state(name=STATE_THREE, state=StateThree())
fsm.add_transition(source=STATE_ONE, dest=STATE_TWO)
fsm.add_transition(source=STATE_TWO, dest=STATE_ONE)
fsm.add_transition(source=STATE_TWO, dest=STATE_THREE)

agent.add_behaviour(fsm)
```

### Templates - Filtragem de Mensagens
As templates são usadas para filtrar mensagens recebidas com base em critérios específicos.

```python
# Template simples - filtrar por performative
template = Template()
template.set_metadata("performative", "request")

# Template com múltiplos critérios
template = Template()
template.sender = "agent1@localhost"
template.to = "agent2@localhost"
template.set_metadata("performative", "inform")
template.set_metadata("ontology", "weather")

# Template com lógica AND
template1 = Template()
template1.sender = "agent1@localhost"

template2 = Template()
template2.set_metadata("performative", "request")

combined = template1 & template2  # Ambas condições

# Template com lógica OR
combined = template1 | template2  # Qualquer uma das condições

# Usar template
agent.add_behaviour(MyBehaviour(), template)
```

---

## Serialização com jsonpickle

### Conceitos Básicos

```python
import jsonpickle

# ============================================
# 1. SERIALIZAÇÃO DE OBJETOS SIMPLES
# ============================================

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

person = Person("João", 25)

# Serializar (objeto → JSON string)
json_str = jsonpickle.encode(person)
print(json_str)
# Output: {"py/object": "__main__.Person", "name": "João", "age": 25}

# Desserializar (JSON string → objeto)
person_copy = jsonpickle.decode(json_str)
print(person_copy.name)  # João
print(person_copy.age)   # 25
```

### Serialização de Objetos Complexos

```python
# ============================================
# 2. OBJETOS ANINHADOS
# ============================================

class Address:
    def __init__(self, street, city):
        self.street = street
        self.city = city

class Person:
    def __init__(self, name, address):
        self.name = name
        self.address = address

address = Address("Rua X", "Braga")
person = Person("Maria", address)

# jsonpickle serializa recursivamente
json_str = jsonpickle.encode(person)

# Desserializar mantém estrutura
person_copy = jsonpickle.decode(json_str)
print(person_copy.address.city)  # Braga

# ============================================
# 3. LISTAS E DICIONÁRIOS
# ============================================

data = {
    "agents": [
        Person("Agent1", Address("Rua A", "Porto")),
        Person("Agent2", Address("Rua B", "Lisboa"))
    ],
    "count": 2
}

json_str = jsonpickle.encode(data)
data_copy = jsonpickle.decode(json_str)
```

### Opções de Serialização

```python
# ============================================
# 4. OPÇÕES AVANÇADAS
# ============================================

# Sem informação de tipo (mais limpo, mas não recupera tipo)
json_str = jsonpickle.encode(person, unpicklable=False)
# Output: {"name": "João", "age": 25}

# Com indentação (legível)
json_str = jsonpickle.encode(person, indent=4)

# Excluir atributos privados
json_str = jsonpickle.encode(person, keys=True)

# Incluir métodos (não recomendado)
json_str = jsonpickle.encode(person, make_refs=False)
```

### Uso em Mensagens SPADE

```python
class DataMessage:
    def __init__(self, data_type, content, timestamp):
        self.data_type = data_type
        self.content = content
        self.timestamp = timestamp

class SenderBehaviour(OneShotBehaviour):
    async def run(self):
        # Criar objeto complexo
        data = DataMessage(
            data_type="sensor_reading",
            content={"temperature": 25.5, "humidity": 60},
            timestamp=datetime.now()
        )
        
        # Serializar
        json_data = jsonpickle.encode(data)
        
        # Enviar em mensagem
        msg = Message(to="receiver@localhost")
        msg.set_metadata("performative", "inform")
        msg.body = json_data
        await self.send(msg)

class ReceiverBehaviour(CyclicBehaviour):
    async def run(self):
        msg = await self.receive(timeout=10)
        
        if msg:
            # Desserializar
            data = jsonpickle.decode(msg.body)
            
            # Usar objeto
            print(f"Tipo: {data.data_type}")
            print(f"Temperatura: {data.content['temperature']}")
            print(f"Timestamp: {data.timestamp}")
```

---

## Comunicação entre Agentes

### FIPA ACL Performatives

| Performative | Significado | Uso |
|--------------|-------------|-----|
| **REQUEST** | Solicitar ação | Pedir a outro agente para fazer algo |
| **INFORM** | Informar facto | Comunicar informação |
| **QUERY-IF** | Questionar (booleano) | Perguntar se algo é verdade |
| **QUERY-REF** | Questionar (referência) | Perguntar valor de algo |
| **AGREE** | Concordar | Aceitar realizar pedido |
| **REFUSE** | Recusar | Recusar realizar pedido |
| **PROPOSE** | Propor | Fazer proposta em negociação |
| **ACCEPT-PROPOSAL** | Aceitar proposta | Aceitar proposta de outro |
| **REJECT-PROPOSAL** | Rejeitar proposta | Rejeitar proposta |
| **CFP** | Call for Proposals | Iniciar negociação |
| **CONFIRM** | Confirmar | Confirmar verdade de informação |
| **DISCONFIRM** | Desconfirmar | Negar verdade de informação |
| **FAILURE** | Falha | Informar que ação falhou |
| **NOT-UNDERSTOOD** | Não compreendido | Não entendeu mensagem |

### Padrões de Conversação

#### Padrão Request-Response

```python
# AGENTE REQUESTER
class RequesterBehaviour(OneShotBehaviour):
    async def run(self):
        # Enviar REQUEST
        msg = Message(to="responder@localhost")
        msg.set_metadata("performative", "request")
        msg.set_metadata("conversation-id", "conv-123")
        msg.body = "Execute task X"
        await self.send(msg)
        
        # Aguardar resposta
        response = await self.receive(timeout=30)
        
        if response:
            perf = response.get_metadata("performative")
            if perf == "agree":
                print("Pedido aceite")
            elif perf == "refuse":
                print("Pedido recusado")

# AGENTE RESPONDER
class ResponderBehaviour(CyclicBehaviour):
    async def run(self):
        msg = await self.receive(timeout=10)
        
        if msg and msg.get_metadata("performative") == "request":
            # Avaliar pedido
            can_do = self.agent.can_execute(msg.body)
            
            # Responder
            reply = msg.make_reply()
            if can_do:
                reply.set_metadata("performative", "agree")
                reply.body = "Will execute"
            else:
                reply.set_metadata("performative", "refuse")
                reply.body = "Cannot execute"
            
            await self.send(reply)
```

#### Padrão Contract Net Protocol

```python
# AGENTE INITIATOR (Manager)
class ContractNetInitiator(OneShotBehaviour):
    async def run(self):
        # 1. Enviar CFP (Call for Proposals)
        participants = ["agent1@localhost", "agent2@localhost"]
        
        for participant in participants:
            msg = Message(to=participant)
            msg.set_metadata("performative", "cfp")
            msg.set_metadata("protocol", "contract-net")
            msg.body = jsonpickle.encode({"task": "delivery", "deadline": "2h"})
            await self.send(msg)
        
        # 2. Receber propostas
        proposals = []
        deadline = time.time() + 10  # 10 segundos para responder
        
        while time.time() < deadline:
            msg = await self.receive(timeout=1)
            if msg and msg.get_metadata("performative") == "propose":
                proposals.append((msg.sender, jsonpickle.decode(msg.body)))
        
        # 3. Selecionar melhor proposta
        if proposals:
            best = min(proposals, key=lambda x: x[1]["cost"])
            winner_jid, winner_proposal = best
            
            # 4. Aceitar vencedor
            accept_msg = Message(to=str(winner_jid))
            accept_msg.set_metadata("performative", "accept-proposal")
            accept_msg.body = "You won the contract"
            await self.send(accept_msg)
            
            # 5. Rejeitar outros
            for participant_jid, proposal in proposals:
                if participant_jid != winner_jid:
                    reject_msg = Message(to=str(participant_jid))
                    reject_msg.set_metadata("performative", "reject-proposal")
                    await self.send(reject_msg)

# AGENTE PARTICIPANT
class ContractNetParticipant(CyclicBehaviour):
    async def run(self):
        msg = await self.receive(timeout=10)
        
        if msg:
            perf = msg.get_metadata("performative")
            
            if perf == "cfp":
                # Recebeu CFP - avaliar e propor
                task = jsonpickle.decode(msg.body)
                
                if self.agent.can_do_task(task):
                    # Calcular proposta
                    cost = self.agent.calculate_cost(task)
                    
                    # Enviar proposta
                    reply = msg.make_reply()
                    reply.set_metadata("performative", "propose")
                    reply.body = jsonpickle.encode({"cost": cost, "time": "1h"})
                    await self.send(reply)
                else:
                    # Recusar participar
                    reply = msg.make_reply()
                    reply.set_metadata("performative", "refuse")
                    await self.send(reply)
            
            elif perf == "accept-proposal":
                print("Proposta aceite! Executar tarefa...")
                # Executar tarefa
            
            elif perf == "reject-proposal":
                print("Proposta rejeitada")
```

---

## Padrões de Comportamento

### Padrão Produtor-Consumidor

```python
class ProducerAgent(Agent):
    class ProduceBehaviour(PeriodicBehaviour):
        async def run(self):
            # Produzir dados
            data = self.agent.produce_data()
            
            # Enviar para consumidores
            for consumer in self.agent.consumers:
                msg = Message(to=consumer)
                msg.set_metadata("performative", "inform")
                msg.body = jsonpickle.encode(data)
                await self.send(msg)
    
    async def setup(self):
        self.consumers = ["consumer1@localhost", "consumer2@localhost"]
        self.add_behaviour(self.ProduceBehaviour(period=5))

class ConsumerAgent(Agent):
    class ConsumeBehaviour(CyclicBehaviour):
        async def run(self):
            msg = await self.receive(timeout=10)
            
            if msg:
                data = jsonpickle.decode(msg.body)
                self.agent.consume_data(data)
    
    async def setup(self):
        template = Template()
        template.set_metadata("performative", "inform")
        self.add_behaviour(self.ConsumeBehaviour(), template)
```

### Padrão Monitor

```python
class MonitorAgent(Agent):
    """Agente que monitoriza outros agentes"""
    
    class MonitorBehaviour(PeriodicBehaviour):
        async def run(self):
            # Pedir status a agentes monitorados
            for agent_jid in self.agent.monitored_agents:
                msg = Message(to=agent_jid)
                msg.set_metadata("performative", "query-ref")
                msg.body = "status"
                await self.send(msg)
    
    class ReceiveStatusBehaviour(CyclicBehaviour):
        async def run(self):
            msg = await self.receive(timeout=5)
            
            if msg:
                status = jsonpickle.decode(msg.body)
                self.agent.update_status(msg.sender, status)
                
                # Verificar alertas
                if status["health"] < 50:
                    print(f"ALERTA: {msg.sender} com saúde baixa!")
    
    async def setup(self):
        self.monitored_agents = ["agent1@localhost", "agent2@localhost"]
        self.agent_status = {}
        
        self.add_behaviour(self.MonitorBehaviour(period=10))
        self.add_behaviour(self.ReceiveStatusBehaviour())
```

### Padrão Coordenador

```python
class CoordinatorAgent(Agent):
    """Coordena múltiplos agentes trabalhadores"""
    
    def __init__(self, jid, password):
        super().__init__(jid, password)
        self.workers = []
        self.task_queue = []
        self.assignments = {}
    
    class DistributeTasksBehaviour(PeriodicBehaviour):
        async def run(self):
            # Distribuir tarefas pendentes
            while self.agent.task_queue:
                task = self.agent.task_queue.pop(0)
                
                # Encontrar trabalhador disponível
                worker = self.agent.find_available_worker()
                
                if worker:
                    # Atribuir tarefa
                    msg = Message(to=worker)
                    msg.set_metadata("performative", "request")
                    msg.body = jsonpickle.encode(task)
                    await self.send(msg)
                    
                    self.agent.assignments[task["id"]] = worker
                else:
                    # Sem trabalhadores - devolver à fila
                    self.agent.task_queue.insert(0, task)
                    break
    
    class ReceiveResultsBehaviour(CyclicBehaviour):
        async def run(self):
            msg = await self.receive(timeout=10)
            
            if msg:
                perf = msg.get_metadata("performative")
                
                if perf == "inform":
                    # Resultado recebido
                    result = jsonpickle.decode(msg.body)
                    print(f"Tarefa {result['task_id']} concluída por {msg.sender}")
                    
                    # Marcar trabalhador como disponível
                    self.agent.mark_worker_available(msg.sender)
    
    async def setup(self):
        self.add_behaviour(self.DistributeTasksBehaviour(period=2))
        self.add_behaviour(self.ReceiveResultsBehaviour())
```

---

## Exemplos Práticos Completos

### Exemplo 1: Sistema de Leilão

```python
import spade
from spade.agent import Agent
from spade.behaviour import CyclicBehaviour, OneShotBehaviour
from spade.message import Message
import jsonpickle
import random

# ============================================
# AGENTE LEILOEIRO (Auctioneer)
# ============================================

class AuctioneerAgent(Agent):
    def __init__(self, jid, password):
        super().__init__(jid, password)
        self.item = {"name": "Quadro Raro", "base_price": 100}
        self.bids = []
        self.bidders = []
    
    class AnnounceBehaviour(OneShotBehaviour):
        async def run(self):
            print(f"[LEILOEIRO] Leilão iniciado: {self.agent.item['name']}")
            print(f"  Preço base: €{self.agent.item['base_price']}")
            
            # Anunciar a todos os licitadores
            for bidder in self.agent.bidders:
                msg = Message(to=bidder)
                msg.set_metadata("performative", "cfp")
                msg.body = jsonpickle.encode(self.agent.item)
                await self.send(msg)
            
            print("[LEILOEIRO] Aguardando licitações...")
    
    class ReceiveBidsBehaviour(CyclicBehaviour):
        async def run(self):
            msg = await self.receive(timeout=15)
            
            if msg and msg.get_metadata("performative") == "propose":
                bid = jsonpickle.decode(msg.body)
                self.agent.bids.append((msg.sender, bid["amount"]))
                print(f"[LEILOEIRO] Licitação recebida de {msg.sender}: €{bid['amount']}")
            
            # Após timeout, decidir vencedor
            if not msg and self.agent.bids:
                await self.close_auction()
        
        async def close_auction(self):
            if self.agent.bids:
                # Encontrar maior licitação
                winner_jid, winning_bid = max(self.agent.bids, key=lambda x: x[1])
                
                print(f"\n[LEILOEIRO] Leilão encerrado!")
                print(f"  Vencedor: {winner_jid}")
                print(f"  Valor: €{winning_bid}")
                
                # Informar vencedor
                winner_msg = Message(to=str(winner_jid))
                winner_msg.set_metadata("performative", "accept-proposal")
                winner_msg.body = f"Parabéns! Venceu com €{winning_bid}"
                await self.send(winner_msg)
                
                # Informar perdedores
                for bidder_jid, bid_amount in self.agent.bids:
                    if bidder_jid != winner_jid:
                        loser_msg = Message(to=str(bidder_jid))
                        loser_msg.set_metadata("performative", "reject-proposal")
                        loser_msg.body = "Não venceu o leilão"
                        await self.send(loser_msg)
            
            await self.agent.stop()
    
    async def setup(self):
        self.bidders = [
            "bidder1@localhost",
            "bidder2@localhost",
            "bidder3@localhost"
        ]
        
        self.add_behaviour(self.AnnounceBehaviour())
        self.add_behaviour(self.ReceiveBidsBehaviour())

# ============================================
# AGENTE LICITADOR (Bidder)
# ============================================

class BidderAgent(Agent):
    def __init__(self, jid, password, max_budget):
        super().__init__(jid, password)
        self.max_budget = max_budget
    
    class BidBehaviour(CyclicBehaviour):
        async def run(self):
            msg = await self.receive(timeout=20)
            
            if msg:
                perf = msg.get_metadata("performative")
                
                if perf == "cfp":
                    # Recebeu anúncio de leilão
                    item = jsonpickle.decode(msg.body)
                    print(f"[{self.agent.jid}] Leilão: {item['name']}, Base: €{item['base_price']}")
                    
                    # Decidir se licitar
                    if item["base_price"] <= self.agent.max_budget:
                        # Fazer licitação (base + margem aleatória)
                        bid_amount = item["base_price"] + random.randint(10, 50)
                        bid_amount = min(bid_amount, self.agent.max_budget)
                        
                        print(f"[{self.agent.jid}] Licitando €{bid_amount}")
                        
                        # Enviar licitação
                        reply = msg.make_reply()
                        reply.set_metadata("performative", "propose")
                        reply.body = jsonpickle.encode({"amount": bid_amount})
                        await self.send(reply)
                    else:
                        print(f"[{self.agent.jid}] Preço base muito alto, não vou licitar")
                
                elif perf == "accept-proposal":
                    # Venceu!
                    print(f"[{self.agent.jid}] 🎉 {msg.body}")
                    await self.agent.stop()
                
                elif perf == "reject-proposal":
                    # Perdeu
                    print(f"[{self.agent.jid}] 😞 {msg.body}")
                    await self.agent.stop()
    
    async def setup(self):
        print(f"[{self.jid}] Pronto para licitar (orçamento: €{self.max_budget})")
        self.add_behaviour(self.BidBehaviour())

# ============================================
# EXECUTAR SISTEMA DE LEILÃO
# ============================================

async def main():
    # Criar leiloeiro
    auctioneer = AuctioneerAgent("auctioneer@localhost", "password")
    await auctioneer.start()
    
    # Criar licitadores
    bidder1 = BidderAgent("bidder1@localhost", "password", max_budget=150)
    bidder2 = BidderAgent("bidder2@localhost", "password", max_budget=200)
    bidder3 = BidderAgent("bidder3@localhost", "password", max_budget=120)
    
    await bidder1.start()
    await bidder2.start()
    await bidder3.start()
    
    # Aguardar conclusão
    await spade.wait_until_finished(auctioneer)

if __name__ == "__main__":
    spade.run(main())
```

---

## Boas Práticas

### 1. Estrutura de Projeto

```
projeto_agentes/
│
├── agents/
│   ├── __init__.py
│   ├── base_agent.py       # Classe base
│   ├── client_agent.py
│   ├── server_agent.py
│   └── monitor_agent.py
│
├── behaviours/
│   ├── __init__.py
│   ├── communication.py
│   └── reasoning.py
│
├── messages/
│   ├── __init__.py
│   ├── protocols.py        # Protocolos de comunicação
│   └── templates.py        # Templates de mensagens
│
├── utils/
│   ├── __init__.py
│   ├── serialization.py
│   └── logging.py
│
├── config.py               # Configurações
├── main.py                 # Ponto de entrada
└── requirements.txt
```

### 2. Logging Adequado

```python
import logging

class AgentWithLogging(Agent):
    async def setup(self):
        # Configurar logger
        self.logger = logging.getLogger(str(self.jid))
        self.logger.setLevel(logging.INFO)
        
        handler = logging.FileHandler(f"{self.jid}.log")
        formatter = logging.Formatter(
            '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
        )
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)
        
        self.logger.info("Agente iniciado")
    
    class MyBehaviour(CyclicBehaviour):
        async def run(self):
            self.agent.logger.debug("Executando comportamento")
            # ...
```

### 3. Tratamento de Erros

```python
class RobustBehaviour(CyclicBehaviour):
    async def run(self):
        try:
            msg = await self.receive(timeout=10)
            
            if msg:
                # Validar mensagem
                if not self.validate_message(msg):
                    self.agent.logger.warning(f"Mensagem inválida de {msg.sender}")
                    return
                
                # Processar
                await self.process_message(msg)
        
        except jsonpickle.JSONDecodeError as e:
            self.agent.logger.error(f"Erro ao desserializar: {e}")
        
        except Exception as e:
            self.agent.logger.error(f"Erro inesperado: {e}")
    
    def validate_message(self, msg):
        """Validar estrutura da mensagem"""
        required_metadata = ["performative", "conversation-id"]
        return all(msg.get_metadata(m) for m in required_metadata)
```

### 4. Configuração Externa

```python
# config.py
import os
from dataclasses import dataclass

@dataclass
class AgentConfig:
    jid: str
    password: str
    xmpp_server: str = "localhost"
    port: int = 5222

@dataclass
class SystemConfig:
    num_agents: int = 10
    timeout: int = 30
    log_level: str = "INFO"

# Carregar de variáveis de ambiente ou ficheiro
def load_config():
    return SystemConfig(
        num_agents=int(os.getenv("NUM_AGENTS", "10")),
        timeout=int(os.getenv("TIMEOUT", "30")),
        log_level=os.getenv("LOG_LEVEL", "INFO")
    )

# main.py
from config import load_config, AgentConfig

config = load_config()

agent_config = AgentConfig(
    jid="agent@localhost",
    password=os.getenv("AGENT_PASSWORD", "default")
)
```

### 5. Testes Unitários

```python
import unittest
from unittest.mock import Mock, AsyncMock
import asyncio

class TestMyAgent(unittest.TestCase):
    def setUp(self):
        self.agent = MyAgent("test@localhost", "password")
    
    def test_initialization(self):
        self.assertEqual(self.agent.jid, "test@localhost")
        self.assertIsNotNone(self.agent.beliefs)
    
    def test_message_handling(self):
        # Criar mensagem mock
        msg = Mock()
        msg.get_metadata.return_value = "request"
        msg.body = "test"
        
        # Testar processamento
        result = self.agent.process_message(msg)
        self.assertTrue(result)

class TestBehaviours(unittest.TestCase):
    async def test_behaviour_execution(self):
        agent = MyAgent("test@localhost", "password")
        behaviour = agent.MyBehaviour()
        
        # Executar comportamento
        await behaviour.run()
        
        # Verificar resultado
        self.assertTrue(behaviour.executed)

if __name__ == "__main__":
    unittest.main()
```

### 6. Documentação

```python
class WellDocumentedAgent(Agent):
    """
    Agente bem documentado que demonstra boas práticas.
    
    Este agente é responsável por:
    - Monitorizar sensores
    - Enviar alertas quando necessário
    - Comunicar com agente central
    
    Attributes:
        sensors (list): Lista de sensores monitorizados
        threshold (float): Limite para alerta
        central_agent (str): JID do agente central
    
    Example:
        >>> agent = WellDocumentedAgent("monitor@localhost", "pass")
        >>> await agent.start()
    """
    
    def __init__(self, jid, password, threshold=100):
        """
        Inicializa o agente monitor.
        
        Args:
            jid (str): Jabber ID do agente
            password (str): Password para autenticação
            threshold (float): Limite para alerta (default: 100)
        """
        super().__init__(jid, password)
        self.threshold = threshold
    
    class MonitorBehaviour(PeriodicBehaviour):
        """
        Comportamento periódico que monitoriza sensores.
        
        Executa a cada 5 segundos e verifica:
        1. Estado de cada sensor
        2. Se valores excedem threshold
        3. Envia alerta se necessário
        """
        async def run(self):
            """Executa ciclo de monitorização"""
            for sensor in self.agent.sensors:
                value = sensor.read()
                
                if value > self.agent.threshold:
                    await self.send_alert(sensor, value)
        
        async def send_alert(self, sensor, value):
            """
            Envia alerta ao agente central.
            
            Args:
                sensor: Sensor que gerou alerta
                value (float): Valor lido
            """
            msg = Message(to=self.agent.central_agent)
            msg.set_metadata("performative", "inform")
            msg.body = f"ALERTA: {sensor.id} = {value}"
            await self.send(msg)
```

---

## Conclusão

Este guia fornece os **padrões base e universais** para criar agentes em Python:

### Procedimentos Universais

1. **Perceção**: Recolher informação do ambiente e mensagens
2. **Raciocínio**: Avaliar estado e decidir ações
3. **Ação**: Executar decisões e comunicar
4. **Loop**: Ciclo contínuo perceção-raciocínio-ação

### Componentes Essenciais

- Estado interno (beliefs, goals, intentions)
- Comportamentos (cyclic, oneshot, periodic, FSM)
- Comunicação (mensagens ACL, performatives)
- Serialização (jsonpickle para objetos complexos)

### Frameworks Recomendados

- **SPADE**: Multi-agente baseado em XMPP
- **jsonpickle**: Serialização de objetos Python
- **asyncio**: Programação assíncrona

Com estes padrões, pode criar qualquer tipo de agente, desde simples reativos até sistemas multi-agente complexos com coordenação, negociação e aprendizagem.

---

**Referências:**
- Russell & Norvig - Artificial Intelligence: A Modern Approach
- Wooldridge - An Introduction to MultiAgent Systems
- SPADE Documentation: https://spade-mas.readthedocs.io/
- FIPA Standards: http://www.fipa.org/

**Última atualização:** Outubro 2025
