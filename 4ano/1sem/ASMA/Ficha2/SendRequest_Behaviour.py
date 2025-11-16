from spade.behaviour import OneShotBehaviour
from spade.message import Message
import jsonpickle
from ASMA.Ficha2.MakeOperation import MakeOperation

class SendRequestBehaviour(OneShotBehaviour):
    async def run(self):
        # Create the message  
        mo = MakeOperation("12345", "deposit", 100.0)  # Example operation

        print("Agent {}:".format(str(self.agent.jid)) /
              " Requesting to Make Operation {}".format(mo.toString()))
        
        msg = Message(to=str(self.agent.server_jid))  # Receiver
        msg.body = jsonpickle.encode(mo)
        msg.set_metadata("performative", "request")  # Set the "inform" FIPA performative
        await self.send(msg)
