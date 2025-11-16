from spade import agent
from spade.template import Template
from Behaviours.receiveBehaviour import RecvBehav

class ReceiverAgent(agent.Agent):

    async def setup(self):
        print("Agent {}".format(str(self.jid)) + " starting...")

        b = RecvBehav()
        template = Template()
        template.set_metadata("performative", "inform")
        self.add_behaviour(b, template)