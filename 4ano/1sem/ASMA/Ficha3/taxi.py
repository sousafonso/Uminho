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

class TaxiAgent(Agent):
    """
    Agente Taxi que transporta clientes
    """
    def __init__(self, jid, x_loc=None, y_loc=None):
        super().__init__(jid, None)
        self.location = Location(x_loc, y_loc) if x_loc and y_loc else random_location()
        self.available = True
        self.manager_jid = "manager@localhost"
        self.transport_duration = 3  # segundos