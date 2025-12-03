import json
import os
from autogen import AssistantAgent
from autogen import UserProxyAgent
from autogen import GroupChat
from autogen import GroupChatManager


"""

    Sistema Multiagente com 3 agentes:
    - TravelAgent(Controller) que coordena o processo e recebe o pedido inicial
    - PlannerAgent que constroi um itinerario consistente de 3 dias para um destino
    - BudgetAgent que estima custos aproximados (voo, alojamento e atividades) e valida se o plano cabe no orcamento indicado

"""

config_list = [{
    "model": os.getenv("LLM_MODEL", "gemma3:1b"),
    "api_key": os.getenv("OPENAI_API_KEY", "ollama_key"),
    "base_url": os.getenv("OPENAI_API_BASE", "http://localhost:11434/v1")
}]

LLM_KW = {"config_list": config_list, "timeout": 120, "temperature": 0.2}


travel_agent = AssistantAgent(
    name = "TravelAgent",
    system_message = "Você é o TravelAgent, um assistente de planeamento de viagens. Você coordena com o PlannerAgent e o BudgetAgent para criar um itinerário de viagem de 3 dias com base nas preferências e orçamento do utilizador.",
    llm_config = LLM_KW,
)

planner_agent = AssistantAgent(
    name = "PlannerAgent",
    system_message = "Você é o PlannerAgent, responsável por criar um itinerário detalhado de 3 dias com base nas preferências do utilizador fornecidas pelo TravelAgent.",
    llm_config = LLM_KW,
)

budget_agent = AssistantAgent(
    name = "BudgetAgent",
    system_message = "Você é o BudgetAgent, responsável por estimar os custos (voos, alojamento, atividades) para o itinerário criado pelo PlannerAgent e garantir que se enquadra no orçamento do utilizador.",
    llm_config = LLM_KW,
)

user_proxy = UserProxyAgent(
    name = "UserProxy",
    code_execution_config = False,
    human_input_mode = "NEVER",
    system_message = "Você é o UserProxy, simulando interações do utilizador para testar o sistema de planeamento de viagens.",
    llm_config = LLM_KW,
)

groupchat = GroupChat(
    agents = [user_proxy, travel_agent, planner_agent, budget_agent],
    messages = [],
    max_round = 6,
    speaker_selection_method = "round_robin"
)

manager = GroupChatManager(
    groupchat = groupchat,
    name = "Manager",
    llm_config = LLM_KW,
)

# Simulação de user
user_proxy.initiate_chat(
    manager,
    message = "Quero planear uma viagem de 3 dias a Paris com um orçamento de 1500 euros. Por favor, ajudem-me a criar um itinerário detalhado incluindo voos, alojamento e atividades. Pretendo fazer a viagem no mês de dezembro. A visita ao museu do louvre é obrigatória"
)