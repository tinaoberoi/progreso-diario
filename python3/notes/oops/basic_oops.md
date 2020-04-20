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

## Attributes
* __init__(), this method is used to initialize the attributes of an object.
* __init__() is automatically called right after the object is created
```python
class Car:
	def __init__(self, model_no):
		self.model_no = model_no

accord = Car(model_no = 1908)
```
```python
class Dog:
    
    # Class Object Attribute
    species = 'mammal'
    
    def __init__(self,breed,name):
        self.breed = breed
        self.name = name

sam = Dog('Lab','Sam')

sam.name
'Sam'
#Note that the Class Object Attribute is defined outside of any methods in the class. Also by convention, we place them first before the init.

sam.species
'mammal'
```

## Methods
* Methods are functions defined inside body of class.
* They are functions acting on an object that take the Object itself into account through its self argument.
```python
class Circle:
	pi = 3.14

    # Circle gets instantiated with a radius (default is 1)
	def __init__(self, radius = 1):
		self.radius = radius
		self.area = Circle.pi * radius* radius
	# Method for resetting Radius
	def setRadius(self,radius):
		self.radius = radius
		self.area = Circle.pi * radius* radius
	def circumference(self):
		return 2*self.pi*self.radius

c = Circle()

print('Radius is: ',c.radius)
print('Area is: ',c.area)
print('Circumference is: ',c.getCircumference())

```
Radius is:  1
Area is:  3.14
Circumference is:  6.28

* In the __init__ method above, in order to calculate the area attribute, we had to call Circle.pi. This is because the object does not yet have its own .pi attribute, so we call the Class Object Attribute pi instead.
* In the setRadius method, however, we'll be working with an existing Circle object that does have its own pi attribute. Here we can use either Circle.pi or self.pi.
```python
c.setRadius(2)

print('Radius is: ',c.radius)
print('Area is: ',c.area)
print('Circumference is: ',c.getCircumference())
```
Radius is:  2
Area is:  12.56
Circumference is:  12.56