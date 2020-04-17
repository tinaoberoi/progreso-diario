# Warmup Excercises
def lesser_of_two_evens(a,b):
	if(a<b):
		return a
	else:
		return b

#print(lesser_of_two_evens(2,4))

def animal_crackers(text):
	words = text.split()
	if(words[0] == words[1]):
		return True
	return False

#print(animal_crackers('Crazy Kangaroo'))	

def makes_twenty(n1,n2):
	if(n1==20 or n2==20 or (n1+n2)==20):
		return True
	else:
		return False

#print(makes_twenty(10,10))


# Level1
def old_macdonald(name):
	return name[:3].capitalize()+name[3:].capitalize()

#print(old_macdonald('macdonald'))

def master_yoda(text):
	b = text[::-1]
	my_list=b.split()
	res = ""
	for i in my_list:
		res+=i[::-1]
		res+=" "
	return res

#print(master_yoda('I am home'))
#print(master_yoda('We are ready'))

def almost_there(n):
	low1 = 90
	low2 = 190
	high1 = 110
	high2 = 210
	if(low1<=n<=high1 or low2<=n<=high2):
		return True
	return False

#print(almost_there(209))

#Level2
def has_33(nums):
	l = len(nums)
	index = 0
	for i, x in enumerate(nums):
		if(x == 3):
			index = i
			break
	#print(i)
	if(i==l-1):
		return False
	if(i<l and nums[i+1] == 3):
		return True
	return False

#print(has_33([3, 1, 3]))

def paper_doll(text):
	res = ""
	for char in text:
		res+=char*3
	return res
#print(paper_doll('Hello'))

def blackjack(a, b, c):
	s = sum((a, b, c)) 
	if(s <= 21):
		return s;
	if(s >21 and 11 in (a, b, c)):
		return s-10
	else:
		return 	"BUST"

#print(blackjack(9,9,9))

#Challenging Problems

def spy_game(nums):
	index = 0
	for i, n in enumerate(nums):
		if(n == 0):
			index = i
			break
	if(nums[index:index+3] == [0, 0, 7]):
		return True
	return False
#print(spy_game([1,0,2,4,0,5,7]))

import math

def ifprime(num):
	if(num%2 == 0 and num>2):
		return False
	for i in range(3, sqrt(num)+1, 2):
		if(num%i == 0):
			return False
	return True

def count_primes(num):
	count = 0;
	for i in num:
		if(ifprime(i)):
			count+=1
	return count

print(count_primes(100))
	