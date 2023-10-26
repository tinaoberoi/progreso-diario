# Inheritance
* Inheritance is the way to form new classes from the classes already defined.
* Classes we derive from -> base class, new formed class -> derived class.
* Derived class override or extends the functionality of base classes. 
* Importance : code reuse

```python
class Animal:
    def __init__(self):
        print("Animal created")

    def whoAmI(self):
        print("Animal")

    def eat(self):
        print("Eating")


class Dog(Animal):
    def __init__(self):
        Animal.__init__(self)
        print("Dog created")

    def whoAmI(self):
        print("Dog")

    def bark(self):
        print("Woof!")
```
```python
d = Dog()
```
Animal created
Dog created

```python
d.whoAmI()
```
Dog
```python
d.eat()
```
Eating
```python
d.bark()
```
Woof!

* Animal => base class, Dog => derived class
The derived class inherits the functionality of the base class.

It is shown by the eat() method.
The derived class modifies existing behavior of the base class.

shown by the whoAmI() method.
Finally, the derived class extends the functionality of the base class, by defining a new bark() method.
