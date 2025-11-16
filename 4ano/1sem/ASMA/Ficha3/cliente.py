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
from features import Location, random_location

class ClientAgent(Agent):
    """
    Agente Client que solicita transporte
    """
    def __init__(self, jid, x_pos=None, y_pos=None, x_dest=None, y_dest=None):
        super().__init__(jid, None)
        
        # Gerar localizações aleatórias se não fornecidas
        self.current_location = Location(x_pos, y_pos) if x_pos and y_pos else random_location()
        self.destination = Location(x_dest, y_dest) if x_dest and y_dest else random_location()
        self.manager_jid = "manager@localhost"
        self.waiting_response = True