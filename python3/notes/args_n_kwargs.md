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

* Args creates tuple of values, kwargs create dictionaries of values

```python

def myfunc(**kwargs):
    if 'fruit' in kwargs:
        print(f"My favorite fruit is {kwargs['fruit']}")  # review String Formatting and f-strings if this syntax is unfamiliar
    else:
        print("I don't like fruit")
        
myfunc(fruit='pineapple')
My favorite fruit is pineapple
myfunc()
I don't like fruit
```
# Args and Kwargs together
* You can pass *args and **kwargs into the same function, but *args have to appear before **kwargs
```python
def myfunc(*args, **kwargs):
    if 'fruit' and 'juice' in kwargs:
        print(f"I like {' and '.join(args)} and my favorite fruit is {kwargs['fruit']}")
        print(f"May I have some {kwargs['juice']} juice?")
    else:
        pass
        
myfunc('eggs','spam',fruit='cherries',juice='orange')
I like eggs and spam and my favorite fruit is cherries
May I have some orange juice?
```