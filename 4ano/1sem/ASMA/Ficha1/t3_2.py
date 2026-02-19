import asyncio
from spade.agent import Agent
from spade.behaviour import CyclicBehaviour, OneShotBehaviour
from spade.message import Message

class ReceiverAgent(Agent):
    class ReceiveMsgBehaviour(CyclicBehaviour): # Behaviour para receber mensagens de forma cíclica, ou seja, executa continuamente até ser parado ou o timeout ser atingido
        async def run(self):
            msg = await self.receive(timeout=10)
            if msg:
                print(f"Mensagem recebida: {msg.body}")
            else:
                print("Nada recebido neste ciclo.")

    async def setup(self):
        print("Receiver Agent iniciado")
        self.add_behaviour(self.ReceiveMsgBehaviour())

class SenderAgent(Agent):
    class SendMsgBehaviour(OneShotBehaviour): # Behaviour para enviar mensagens de forma única, ou seja, executa uma vez e termina
        async def run(self):
            msg = Message(to="receiver_agent@localhost")
            msg.body = "Olá, esta é a mensagem do sender!"
            await self.send(msg)
            print("Mensagem enviada pelo sender.")

    async def setup(self):
        print("Sender Agent iniciado")
        self.add_behaviour(self.SendMsgBehaviour())

async def main():
    receiver = ReceiverAgent("receiver_agent@localhost", "passwordreceiver")
    sender = SenderAgent("sender_agent@localhost", "passwordsender")

    await receiver.start(auto_register=True)
    await asyncio.sleep(1)  # espera o receptor iniciar
    await sender.start(auto_register=True)

    # Mantém agentes a correr por algum tempo para troca de mensagens
    await asyncio.sleep(10)

    await sender.stop()
    await receiver.stop()

if __name__ == "__main__":
    asyncio.run(main())
