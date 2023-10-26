class Account:
	
	def __init__(self, owner, balance=0):
		print("Account created")
		self.owner = owner
		self.balance = balance
	def __str__(self):
		return ("Account owner: {0}\nAccount balance: {1}".format(self.owner, self.balance))
	def deposit(self, amount):
		self.balance += amount
		print("Deposit Accepted")
		
	def withdraw(self, amount):
		if(self.balance < amount):
			print("Funds Unavailable!")
			return
		self.balance-=amount
		print("withdrawal Accepted")
		

acct1 = Account('Jose',100)
print(acct1)
acct1.owner
acct1.deposit(50)
acct1.withdraw(75)
acct1.withdraw(500)