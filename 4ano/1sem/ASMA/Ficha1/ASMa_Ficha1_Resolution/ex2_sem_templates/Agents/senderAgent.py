from spade import agent
from Behaviours.sendBehaviour import InformBehav

class SenderAgent(agent.Agent):
    async def setup(self):
        print("Agent {}".format(str(self.jid)) + " starting...")
        
        b = InformBehav()
        self.add_behaviour(b)