# Problem 1
def gensquares(N):
    for x in range(N):
    	yield x**2

for x in gensquares(10):
    print(x)

print("----------------------------------------------------------\n")

#Problem 2
import random

def rand_num(low,high,n):
	for x in range(n):
		yield random.randint(low, high)

for num in rand_num(1,10,12):
    print(num)

print("----------------------------------------------------------\n")

#Problem 3
s = 'hello'
some_iter = iter(s)
print(next(some_iter))