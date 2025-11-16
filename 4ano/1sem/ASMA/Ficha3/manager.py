import spade
from spade.agent import Agent
from spade.behaviour import CyclicBehaviour, OneShotBehaviour, PeriodicBehaviour
from spade.message import Message
from spade.template import Template
import jsonpickle
import random
import asyncio
import math
from datetime import datetime

class ManagerAgent(Agent):
    """
    Agente Manager que coordena táxis e clientes
    """
    def __init__(self, jid):
        # Não utiliza password; passa None explicitamente ao inicializar o Agent
        super().__init__(jid, None)
        self.available_taxis = {}  # {taxi_jid: TaxiInfo}
        self.pending_requests = []