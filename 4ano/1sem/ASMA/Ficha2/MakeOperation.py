class MakeOperation:
    def __init__ (self, accountId: str, type:str, amount: float):
        self.accountId = accountId
        self.type = type
        self.amount = amount

    def getAmount(self):
        return self.amount
    def getType(self):
        return self.type
    def getAccountId(self):
        return self.accountId
    def setAmount(self, amount):
        self.amount = amount
    def setType(self, type):
        self.type = type
    def setAccountId(self, accountId):
        self.accountId = accountId

    def toString(self):
        return f"AccountId: {self.accountId}, Type: {self.type}, Amount: {self.amount}"