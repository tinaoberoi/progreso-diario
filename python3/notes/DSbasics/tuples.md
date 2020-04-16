# Tuples in Python

* Similar to lists but immutable
* [Read this](https://github.com/Pierian-Data/Complete-Python-3-Bootcamp/blob/master/00-Python%20Object%20and%20Data%20Structure%20Basics/06-Tuples.ipynb)

## Basic tuple methods:
```python
```
* len(t)
```python
t = ('one', 2, 3)

len(t)
3
```
* slicing similar in lists
* t.index():  Use .index to enter a value and return the index

**When to use Tuples, if fewer methods than lists**
If in your program you are passing around an object and need to make sure it does not get changed, then a tuple becomes your solution.