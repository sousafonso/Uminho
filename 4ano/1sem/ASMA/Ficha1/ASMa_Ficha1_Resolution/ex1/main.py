import time
import spade
from Agents.helloAgent import HelloAgent

XMPP_SERVER="localhost" # your XMPP_SERVER
PASSWORD="NOPASSWORD" #your password

async def main():
    """ 
    HELLOWORLD AGENT EXAMPLE
    """
    # create agent instance and connect it to XMPP server
    helloworld_agent = HelloAgent("helloagent@"+XMPP_SERVER, PASSWORD)
    await helloworld_agent.start()

    

if __name__ == '__main__':
    spade.run(main())


   

