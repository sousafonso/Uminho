import json
import os
from autogen.agent.agent import AssistantAgent
from autogen.agent.user_proxy_agent import UserProxyAgent
from autogen.chat.group_chat import GroupChat


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
    system_message = "You are TravelAgent, a travel planning assistant. You coordinate with PlannerAgent and BudgetAgent to create a 3-day travel itinerary based on user preferences and budget.",
    llm_config = LLM_KW,
)

planner_agent = AssistantAgent(
    name = "PlannerAgent",
    system_message = "You are PlannerAgent, responsible for creating a detailed 3-day travel itinerary based on user preferences provided by TravelAgent.",
    llm_config = LLM_KW,
)

budget_agent = AssistantAgent(
    name = "BudgetAgent",
    system_message = "You are BudgetAgent, responsible for estimating costs (flights, accommodation, activities) for the itinerary created by PlannerAgent and ensuring it fits within the user's budget.",
    llm_config = LLM_KW,
)

user_proxy = UserProxyAgent(
    name = "UserProxy",
    code_execution_enabled = False,
    human_input_mode = "Never",
    system_message = "You are UserProxy, simulating user interactions for testing the travel planning system.",
    llm_config = LLM_KW,
)

groupchat = GroupChat(
    agents = [user_proxy, travel_agent, planner_agent, budget_agent],
    messages = [],
    max_rounds = 6,
    speaker_selection_method = "round_robin"
)

manager = GroupChatManager(
    group_chat = groupchat,
    name = "Manager",
    llm_config = LLM_KW,
)

# Simulação de user
user_proxy.initialize_chat(
    manager,
    message = "Quero planear uma viagem de 3 dias a Paris com um orçamento de 1500 euros. Por favor, ajudem-me a criar um itinerário detalhado incluindo voos, alojamento e atividades."
)