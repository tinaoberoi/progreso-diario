# Args in Python3

* Helps in giving function arbitrary number of arguments.
* When a function parameter starts with an asterisk, it allows for an arbitrary number of arguments, and the function takes them in as a tuple of values.

```python
def double_sum(a, b):
	return sum(a,b)*2

#if I need more than 1 arguments
def double_sum(a=0, b=0, c=0, d=0):
	return sum(a,b,c,d)*2

def double_sum(*args):
	return sum(*args)*2
```
# Kwargs in Python
