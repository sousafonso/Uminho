from spade.behaviour import CyclicBehaviour

class RecvBehav(CyclicBehaviour):

    async def on_start(self):
        print("RecvBehav running")

    async def run(self):
        msg = await self.receive(timeout=10) # wait for a message for 10 seconds
        
        if msg:
            p = msg.get_metadata('performative')
            if p == 'inform':
                print("Agent {}:".format(str(self.agent.jid)) + "Message received with content: {}".format(msg.body))
            else:
                 print("Agent {}:".format(str(self.agent.jid)) + "Don't understand")
        else:
            print("Agent {}:".format(str(self.agent.jid)) + "Did not received any message after 10 seconds")
        
        self.kill()

    async def on_end(self):
        print("Agent {}:".format(str(self.agent.jid)) + "RecvBehav finished with exit code {}.".format(self.exit_code))
        await self.agent.stop()