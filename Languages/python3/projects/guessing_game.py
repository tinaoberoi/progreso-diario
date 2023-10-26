from random import randint

print("WELCOME TO GUESS ME!")
print("I'm thinking of a number between 1 and 100")
print("If your guess is more than 10 away from my number, I'll tell you you're COLD")
print("If your guess is within 10 of my number, I'll tell you you're WARM")
print("If your guess is farther than your most recent guess, I'll say you're getting COLDER")
print("If your guess is closer than your most recent guess, I'll say you're getting WARMER")
print("LET'S PLAY!")

x = randint(1, 100)
print(x)
if(x>10):
	l_range = x-10
u_range = x+10
y = int(input('Guess a number: '))
print(y)


if(y < 1 or y>100):
	print("Out of Bounds")
else:
	if(l_range<=y<=u_range):
		print("WARM")
	else:
		print("COLD")

diff = abs(y-x)

while(y != x):
    y = int(input('Guess a number: '))
    if(y < 1 or y>100):
    	print("Out of Bounds")
    else:
    	new_diff = abs(y-x)
    	if(new_diff < diff):
    		print("WARMER")
    	else:
    		print("COLDER")
    	diff = new_diff
