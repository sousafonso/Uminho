from spade import agent

class HelloAgent(agent.Agent):
    async def setup(self):
        print("Agent {}".format(str(self.jid)) + " starting...")