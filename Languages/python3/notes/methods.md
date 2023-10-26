# Methods in python3

* Methods are functions built into objects.
* Methods perform specific actions on object and can also take arguments.
* Eg: object.method(arg1,arg2,etc...)
* methods can have an argument 'self' referring to the object itself.
## Some common Methods on list: 
* append() allows us to add elements to the end of a list:
```python
lst.append(1)
``` 
* The count() method will count the number of occurrences of an element in a list.
```python
lst.count(2)
```
* Other methods are: sort, append, count, extend, insert, pop, remove, reverse, sort
* extend:  adds the specified list elements (or any iterable) to the end of the current list
* list.insert(index, obj): 
  index − This is the Index where the object obj need to be inserted.
  obj − This is the Object to be inserted into the given list.
  The insert() method inserts object obj into list at offset index.
```python
# extend
>>> list1 = ['a', 'b', 'c']
>>> list2 = ['x', 'y', 'z']
>>> list1.extend(list2)
>>> list1
['a', 'b', 'c', 'x', 'y', 'z']
# insert
>>> list1.insert(1, 'newtext')
>>> list1
['a', 'newtext', 'b', 'c', 'x', 'y', 'z']
>>> 
#remove
>>> list2
['x', 'y', 'z']
>>> list2.remove('x')
>>> list2
['y', 'z']
```