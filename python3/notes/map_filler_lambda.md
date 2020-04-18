# Maps in Python3
The map function allows you to "map" a function to an iterable object. That is to say you can quickly call the same function to every item in an iterable, such as a list
```python
def sqaure(num):
	return num**2

my_nums = [1, 2, 3, 4]

list(map(sqaure, my_nums))
[1, 4, 8, 16]
```

# Filler Functions
The filter function returns an iterator yielding those items of iterable for which function(item) is true. Meaning you need to filter by a function that returns either True or False. Then passing that into filter (along with your iterable) and you will get back only the results that would return True when passed to the function.

```python
def check_even(num):
	return num%2 == 0

nums = [0, 1, 2, 3]

list(filter(check_even, nums))
[0, 2]
```
# Lambda Expression
lambda expressions allow us to create "anonymous" functions. This basically means we can quickly make ad-hoc functions without needing to properly define a function using def.

```python
def sqaure(num):
	result = num**2
	return result

def sqaure(num):
	return num**2

sqaure = lambda num:num**2
sqaure(5)
25
list(map(lambda num:num**2, num))
```

```python
def check_even(num):
	if(num%2 == 0):
		return true
	return false

def check_even(num):
	return num%2 == 0

check_even = lambda num : num%2==0
list(filter(lambda num : num%2==0, mylist))
```

* Lambda Function for grabbing first char of string
```python
lambda s: s[0]
list(map(lambda s: s[0], mylist))
```
* Lambda Function to reverse string
```python
lambda s : s[::-1]
```
* Lambda function to return sum
```python
lambda x, y: x+y
```