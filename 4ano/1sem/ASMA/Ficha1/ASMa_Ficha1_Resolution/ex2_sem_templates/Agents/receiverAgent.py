from spade import agent
from Behaviours.receiveBehaviour import RecvBehav

class ReceiverAgent(agent.Agent):

    async def setup(self):
        print("Agent {}".format(str(self.jid)) + " starting...")

        b = RecvBehav()
        self.add_behaviour(b)