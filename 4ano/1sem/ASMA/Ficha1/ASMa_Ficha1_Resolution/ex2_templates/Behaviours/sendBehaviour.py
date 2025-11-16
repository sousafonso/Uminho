from spade.behaviour import OneShotBehaviour
from spade.message import Message
    
class InformBehav(OneShotBehaviour):
    async def run(self):
        print("InformBehav running")
        
        msg = Message(to=self.agent.get("receiver_jid"))                    # Instantiate the message
        msg.set_metadata("performative", "inform")                          # Set the "inform" FIPA performative
        msg.body = "Hello Receiver"                                         # Set the message content
        await self.send(msg)
        print("Agent {}:".format(str(self.agent.jid)) + "Message sent!")

        # set exit_code for the behaviour
        self.exit_code = "Job Finished!"

        # stop agent from behaviour
        await self.agent.stop()