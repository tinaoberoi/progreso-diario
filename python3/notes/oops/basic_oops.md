# Intro to OOPS Python3
```python
class NameOfClass():
	def __init__(self, param1, param2):
		self.param1 = param1
		self.param2 = param2
	def some_method(self):
		print(self.param1)
```

## Objects
* We used type() to check type of object. 
* int, float, string all are objects.
* We can create an object of our own.

## Class
* For creating user defined objects
* Class = blueprint that defines the nature of the object
* From class we construct instances, instances are specific objects craeted from a particular class
```python
class Sample:
	pass

# Instance of class
x = Sample()

print(type(x))
```
<class __main__.Sample>
* Inside class we can define attributes and methods
* Attributes are characteristic of an object, methods are operation we can perform on object.
* Eg: Class car, attribute = (model no, plate no., color) methods = (driving, speed lights)