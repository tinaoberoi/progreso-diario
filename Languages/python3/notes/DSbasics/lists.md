# List in Python3

* Unlike strings, they are mutable, meaning the elements inside a list can be changed!
* Lists are constructed with brackets [] and commas separating every element in the list.
* [Read this](https://github.com/Pierian-Data/Complete-Python-3-Bootcamp/blob/master/00-Python%20Object%20and%20Data%20Structure%20Basics/04-Lists.ipynb)

## Basic List Methods

* list.append() : Use the append method to permanently add an item to the end of a list  

```python
list1 = [1,2,3]
list1.append('new_item')
list1
[1, 2, 3, 'new_item']
```
* pop() : Use pop to "pop off" an item from the list. By default pop takes off the last index, but you can also specify which index to pop off.
* It should also be noted that lists indexing will return an error if there is no element at that index
```python
list1[1000]

IndexError: list index out of range
```
* list.sort()
* list.reverse()