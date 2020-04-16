# Strings in Python
* use len() to find length of string

## Slicing

* syntax: [start: stop : step]
* stop index is not including but upto
```python
s = 'Hello World'
# Grab everything from index = 1 to len(s)
s[1:]
ello World

#Grab everything upto 3rd index (not including 3rd)
s[:3]
Hel

#Everything
s[:]
Hello World
```
* Using negative index to loop backwards
```python
# Last letter (one index behind 0 so it loops back around)
s[-1:]
d

s[-1]
Hello Worl
```
* Using step size
```python
# Grab everything, but go in steps size of 1
s[::1]
'Hello World'

# Grab everything, but go in step sizes of 2
s[::2]
'HloWrd'

# We can use this to print a string backwards
s[::-1]
'dlroW olleH'
```

## Built-in String Functions
* s.upper()
```python
s
'Hello World concatenate me!'
# Upper Case a string
s.upper()
'HELLO WORLD CONCATENATE ME!'
```
* s.lower()
```python
# Lower case
s.lower()
'hello world concatenate me!'
```
* s.split()
```python
# Split a string by blank space (this is the default)
s.split()
['Hello', 'World', 'concatenate', 'me!']

# Split by a specific element (doesn't include the element that was split on)
s.split('W')
['Hello ', 'orld concatenate me!']
```


## Print formatting
* We can use the .format() method to add formatted objects to printed string statements
```python
'Insert another string with curly brackets: {}'.format('The inserted string')

'Insert another string with curly brackets: The inserted string'
```

## Strings are non mutable

* Strings are not mutable! (meaning you can't use indexing to change individual elements of a string)
* Cant change the string as in c++
* s[0] = 'somechar' gives error
* Solution: use slicing and concatenation

## Float formatting follows
 * {value:width.precision f}

# Awesome string formatting resource {https://pyformat.info/}