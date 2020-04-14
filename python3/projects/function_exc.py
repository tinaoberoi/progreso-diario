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
	ans = ''
	count = 0
	for s in name:
		print(s)
		if(count == 0 and count == 3):
			ans+=s.upper()
			print(ans)
			count+=1
		else:
			ans+=s
			print(ans)
			count+=1
	return ans

print(old_macdonald('macdonald'))