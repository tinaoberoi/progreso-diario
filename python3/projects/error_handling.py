# Problem1
#try:
#	for i in ['a','b','c']:
#		print(i**2)
#except:
#	print("sorry, there was some error")

#Problem2
try:
	x = 5
	y = 0
	z = x/y
except ZeroDivisionError as e:
	print("Error dividing by 0 ")
finally:
	print("All Done")

#Problem3
def ask():
	while True:
		try:
			x = int(input("Please enter a number: "))
		except:
			print("Looks like you entered something other than a number")
			continue
		else:
			print("Thank you for number, sqaure is {0}".format(x**2))
			break

ask()