# Functions in Python3
* Functions allow us to not have to repeatedly write the same code again and again. Eg: len() on both strings and lists
* Methods used on specific objects. Eg: reverse used in list not on strings
```python
def name_of_function(arg1,arg2):
    '''
    This is where the function's Document String (docstring) goes
    '''
    # Do stuff here
    # Return desired result
```
```python
import math

def is_prime2(num):
	if num%2 == 0 && num>2:
		return false;
	for i in range(3, int(math.sqrt(num))+1, 2):
		if(num%i == 0):
			return false
	return true
```