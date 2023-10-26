# Useful Operators:

* range(), The range function allows you to quickly generate a list of integers.
* this is a generator function, so to actually get a list out of it, we need to cast it to a list with list().

```python
# Notice how 11 is not included, up to but not including 11, just like slice notation!
>>>list(range(0,11))
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```
* enumerate, very useful function to use with for loops
```python
#without enumerate

count = 0

for letter in 'abcde':
    print("At index {} the letter is {}".format(index_count,letter))
    count += 1

#without enumerate
for i, letter in enumerate(abcde):
    print("At index {} the letter is {}".format(index_count,letter))

```
* zip
Notice the format enumerate actually returns, list of tuples, meaning we could use tuple unpacking during our for loop.
```python
>>> list(enumerate('tina'))
[(0, 't'), (1, 'i'), (2, 'n'), (3, 'a')]

```
You can use the zip() function to quickly create a list of tuples by "zipping" up together two lists.
``` python
>>> mylist1 = [1, 2, 3]
>>> mylist2 = ['x', 'y', 'z']
>>> zip(mylist1, mylist2)
<zip object at 0x7fb93d9d64b0>
>>> list(zip(mylist1, mylist2))
[(1, 'x'), (2, 'y'), (3, 'z')]
```
* in operator
```python
>>>x in [1,2,3]
False
>>>x in ['x', 'y', 'z']
True
```
* min and max
```python
>>> mylist1
[1, 2, 3]
>>> max(mylist1)
3
>>> min(mylist1)
1
```
* random
```python
from random import randint
# Return random integer in range [a, b], including both end points.
randint(0,100)

28
```

* Input
```python
input('Enter Something into this box: ')
Enter Something into this box: great job!

'great job!'
```