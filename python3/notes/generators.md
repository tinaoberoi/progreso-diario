# Generators
* Generator functions allow us to write a function that can send back a value and then later resume to pick up where it left off.
* This type of function is a generator in Python, allowing us to generate a sequence of values over time.
* The main difference in syntax will be the use of a **yield** statement.
* The main difference is when a generator function is compiled they become an object that supports an iteration protocol.
* That means when they are called in your code they don't actually return a value and then exit. Instead, generator functions will automatically suspend and resume their execution and state around the last point of value generation.
* The main advantage here is that instead of having to compute an entire series of values up front, the generator computes one value and then suspends its activity awaiting the next instruction. This feature is known as state suspension.
* For Eg: range() function does not produce a list in memory for all values from start to stop. It just keeps track of the last numbr and the step size, to provide flow of numbers.
* If user needed a list he can use list(range())

## Create own generators
```python
def create_sq(n):
	result = []
	for i in range(n):
		result.append(i**2)
	return result

print(create_sq(5))
```
[0, 1, 4, 9, 16]
```python
for x in create_sq(5):
	print(x)
```
0
1
4
9
16
```python
def create_cubes(n):
	for x in range(n):
		yield x**3

print(create_cubes(5))
```
<generator object create_cubes at 0x7f39bd3e75d0>
```python
for x in create_cubes(5):
	print(x)
```
0
1
8
27
64

* a string object supports iteration, but we can not directly iterate over it as we could with a generator function.

[Read this](https://github.com/Pierian-Data/Complete-Python-3-Bootcamp/blob/master/11-Python%20Generators/01-Iterators%20and%20Generators.ipynb)

[Read about Generator and List Comprehensions]
```python
>>> my_list = [1, 3, 5, 9, 2, 6]
>>> filtered_list = [item for item in my_list if item > 3]
>>> print(filtered_list)
[5, 9, 6]
>>> len(filtered_list)
3
>>> # compare to generator expression
... 
>>> filtered_gen = (item for item in my_list if item > 3)
>>> print(filtered_gen)  # notice it's a generator object
<generator object <genexpr> at 0x7f2ad75f89e0>
>>> len(filtered_gen) # So technically, it has no length
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: object of type 'generator' has no len()
>>> # We extract each item out individually. We'll do it manually first.
... 
>>> next(filtered_gen)
5
>>> next(filtered_gen)
9
>>> next(filtered_gen)
6
>>> next(filtered_gen) # Should be all out of items and give an error
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
StopIteration
>>> # Yup, the generator is spent. No values for you!
... 
>>> # Let's prove it gives the same results as our list comprehension
... 
>>> filtered_gen = (item for item in my_list if item > 3)
>>> gen_to_list = list(filtered_gen)
>>> print(gen_to_list)
[5, 9, 6]
>>> filtered_list == gen_to_list
True
>>> 
```