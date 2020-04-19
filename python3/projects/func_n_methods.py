pi = 3.14
def vol(rad):
    v = (4/3)*pi*(rad**3)
    return v

#print(vol(2))

def ran_check(num,low,high):
    return low<num<high

#print(ran_check(5,2,7))

def up_low(s):
    low = 0
    up = 0
    for char in s:
    	if(char.isupper()):
    		up+=1
    	if(char.islower()):
    		low+=1
    print("No. of Upper case chars : {}".format(up))
    print("No. of Lower case chars : {}".format(low))

s = 'Hello Mr. Rogers, how are you this fine Tuesday?'

#up_low(s)

def unique_list(lst):
    x = set()    
    for i in lst:
    	x.add(i)

    lst2 = []
    for i in x:
    	lst2.append(i)
    return lst2

#print(unique_list([1,1,1,1,2,2,3,3,3,3,4,5]))

def multiply(numbers):  
    res = 1;
    for i in numbers:
    	res=res*i
    return res

#print(multiply([1,2,3,-4]))

def palindrome(s):
	s = s.replace(' ', '')
	return s==s[::-1]
#print(palindrome('abcd'))

import string

def ispangram(str1, alphabet=string.ascii_lowercase):
	alphaset = set(alphabet)
	return alphaset <= set(str1.lower())

print(ispangram("The quick brown fox jumps over the lazy dog"))