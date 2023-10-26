# Sublcass in python3

* Vehicle > Car > Mercedes
* Multiple levels! Vehicle would be the parent class, Car would be the Subclass and Mercedes would be an object we create using the Car subclass.
* The Mercedes we just created will inherit all of the attributes and functions associated with the Vehicle parent class and those from the Car class.

Example

```python
class Boss(object):
	def __inti__(self, name, attitude, behaviour, face):
		self.name = name
		self.attitude = attitude
		self.behaviour = behaviour
		self.face = face

	def get_attitude(self):
		return self.attitude

	def get_behaviour(self):
		return self.behaviour

	def get_face(self):
		return self.face
```

What kind of Bosses do we want to be able to make? How about a GoodBoss and a BadBoss?

```python
class GoodBoss(Boss):
	def __init__(self, name, attitude, behaviour, face):
		super().__init__(name, attitude, behaviour, face)
```
** For understanding super use this link **
[Trying to understand super()](https://stackoverflow.com/questions/576169/understanding-python-super-with-init-methods)

Next up, we can define some GoodBoss specific class functions. These can only be used by an object created using the GoodBoss class:

```python
class GoodBoss(Boss):
	def __init__(self, name, attitude, behaviour, face):
		super().__init__(name, attitude, behaviour, face)
	def nurture_talent(self):
	    #A good boss nurtures talent making employees happy!
        print("The employees feel all warm and fuzzy then put their talents to good use.")

    def encourage(self):
        #A good boss encourages their employees!
        print("The team cheers, starts shouting awesome slogans then gets back to work.")
```
For BadBoss

```python
class BadBoss(Boss):
	def __init__(self, name, attitude, behaviour, face):
		super().__init__(name, attitude, behaviour, face)
	def non_supportive(self):
		print("The employees are never supported for their fresh ideas")
	def rutheless(self):
		print("The boss is never compasionate towards employees")
```