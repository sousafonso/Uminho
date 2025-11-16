import time
import spade
from Agents.receiverAgent import ReceiverAgent
from Agents.senderAgent import SenderAgent

XMPP_SERVER="localhost" # your XMPP_SERVER
PASSWORD="NOPASSWORD" #your password

async def main():


    #Exercise 2
    receiver_agent = ReceiverAgent("receiver@"+XMPP_SERVER, PASSWORD)
    await receiver_agent.start()

    sender_agent = SenderAgent("sender@"+XMPP_SERVER, PASSWORD)
    # store receiver_jid in the sender knowledge base
    sender_agent.set("receiver_jid", "receiver@"+XMPP_SERVER)
    await sender_agent.start()
                        
    #await wait_until_finished(sender_agent)
    

if __name__ == '__main__':
    spade.run(main())


    

