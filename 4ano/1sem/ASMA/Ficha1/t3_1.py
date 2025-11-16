from spade.agent import Agent

class HelloWorldAgent(Agent):
    async def setup(self):
        print("Hello new world!")

if __name__ == "__main__":
    hello_agent = HelloWorldAgent("agent@localhost", "password")
    hello_agent.start()
