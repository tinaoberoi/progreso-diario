# Decorators 
* Functions modifying functionality of another function.
* If you want that extra functionality to your function add decorator to myfunction else delete it.
* globals() and locals() can be used to see variables.

## Functions within func
```python
def hello(name='Jose'):
    print('The hello() function has been executed')
    
    def greet():
        return '\t This is inside the greet() function'
    
    def welcome():
        return "\t This is inside the welcome() function"
    
    print(greet())
    print(welcome())
    print("Now we are back inside the hello() function")

hello()
```
The hello() function has been executed
	 This is inside the greet() function
	 This is inside the welcome() function
Now we are back inside the hello() function

```python
# This gies Nameerror
welcome() 
```
Gives Error

```python
def hello(name = 'Jose'):
	print("This is the hello function")

	def greet():
		print("\t This is greet function")
	def welcome():
		print("\t This is welcome function")

	if(name == 'Jose'):
		return greet()
	else:
		return welcome()

x = hello
print (x('tina'))
```
This is the hello function
	 This is welcome function
None

## Function as arguments
```python
def hello():
    return 'Hi Jose!'

def other(func):
    print('Other code would go here')
    print(func())

other(hello)
```
Other code would go here
Hi Jose!

## Creating Decorators
```python
def new_decorator(original_func):
	#function decorating the original function
	def wrap_func():
		print("Some extra code, before the original_func")

	    original_func()
 
    
		print("Some extra code, after the original_func")

	return wrap_func()

def wrap_func():
		print("Some extra code, before the original_func")

func_needs_decorator()
```
This function is in need of a Decorator
```python
func_needs_decorator = new_decorator(func_needs_decorator)
func_needs_decorator()
```
Code would be here, before executing the func
This function is in need of a Decorator
Code here will execute after the func()

* A decorator simply wrapped the function and modified its behavior.
* Let's understand how we can rewrite this code using the @ symbol, which is what Python uses for Decorators:

```python
@new_decorator
def func_needs_decorator():
    print("This function is in need of a Decorator")

func_needs_decorator()
```
Code would be here, before executing the func
This function is in need of a Decorator
Code here will execute after the func()