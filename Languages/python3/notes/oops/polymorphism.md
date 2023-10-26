# Polymorphism
* How different object classes can take same method name
```python
class Dog:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return self.name+' says Woof!'
    
class Cat:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return self.name+' says Meow!' 
    
niko = Dog('Niko')
felix = Cat('Felix')

print(niko.speak())
print(felix.speak())
```
Niko says Woof!
Felix says Meow!

* These are the following ways to demonstrate polymorphism
* For Loop
```python
for pet in [niko,felix]:
    print(pet.speak())
```
Niko says Woof!
Felix says Meow!

* With Functions
```python
def pet_speak(pet):
    print(pet.speak())

pet_speak(niko)
pet_speak(felix)
```
* Using Abstract Classes and inheritance.
* An abstract class is one that never expects to be instantiated.
* Eg: Never an animal object only dogs and cats
```python
class Animal:
    def __init__(self, name):    # Constructor of the class
        self.name = name

    def speak(self):              # Abstract method, defined by convention only
        raise NotImplementedError("Subclass must implement abstract method")


class Dog(Animal):
    
    def speak(self):
        return self.name+' says Woof!'
    
class Cat(Animal):

    def speak(self):
        return self.name+' says Meow!'
    
fido = Dog('Fido')
isis = Cat('Isis')

print(fido.speak())
print(isis.speak())
```
Fido says Woof!
Isis says Meow!

* Real Life Examples:
   - opening different file types - different tools are needed to display Word, pdf and Excel files
   - adding different objects - the + operator performs arithmetic and concatenation