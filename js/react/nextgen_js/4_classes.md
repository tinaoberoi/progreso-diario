# Classes

- blueprints for objects
- class can have both properties and methods.
- properties are variables of classes.
- methods are functions to classes

```js
class Person {
	name = 'Max'
	call = () => {...}
}
```
- usage of class is done using a *new* keyword

```js
const myPerson = new Person()
myPerson.call()
console.log(myPerson.name)
```
- These classes also support Inheritance

```js
class Person extends Master
```


Example

```js
class Human {
  constructor(){
    this.gender = "Male";
  }
  printGender(){
    console.log(this.gender);
  }
}

class Person extends Human {
  constructor(){
    this.name = "Tina";
  }
  printName(){
    console.log(this.name);
  }
}

const myPerson = new Person();
console.log(myPerson.name);
myPerson.printName();
myPerson.printGender();
```
Output
```
"error"
"ReferenceError: Must call super constructor in derived class before accessing 'this' or returning from derived constructor
    at new Person (pohacizoju.js:12:5)
    at pohacizoju.js:19:18
    at https://static.jsbin.com/js/prod/runner-4.1.7.min.js:1:13924
    at https://static.jsbin.com/js/prod/runner-4.1.7.min.js:1:10866"
```
- Must call super constructor in derived class before accessing 'this' or returning from derived constructor

- The super executes the parent constructor to initialize the parent class.
Correction

```js
class Human {
  constructor(){
    this.gender = "Male";
  }
  printGender(){
    console.log(this.gender);
  }
}

class Person extends Human {
  constructor(){
    super();
    this.name = "Tina";
  }
  printName(){
    console.log(this.name);
  }
}

const myPerson = new Person();
console.log(myPerson.name);
myPerson.printName();
myPerson.printGender();
```
Output

```
"Tina"
"Tina"
"Male"
```
Now you can change var in derived class

```js
class Human {
  constructor(){
    this.gender = "Male";
  }
  printGender(){
    console.log(this.gender);
  }
}

class Person extends Human {
  constructor(){
    super();
    this.name = "Tina";
    this.gender = "Female";
  }
  printName(){
    console.log(this.name);
  }
}

const myPerson = new Person();
console.log(myPerson.name);
myPerson.printName();
myPerson.printGender();
```
Ouput

```
"Tina"
"Tina"
"Female"
```
## New ways to write classes

Prperties in ES6

```js
constructor(){
	this.myProperty = 'Value';
}
```

Property in ES7
(here we skip the constructor call, though behind the scene this will be transformed to use constructor func)
```js
myProperty = 'Value';
```
Methods in ES6

```js
myMethod (){...}
````
Methods in ES7
(Here we think of method as a property which stores a fucntion as a value and then you end up with that)
```js
myMethod = () => {...}
```
#### Advt of this? 

since we use an arrow func as a prop value here you have no problems with this keyword.

```js
class Human {
  gender = "Male";

  printGender= () => {
    console.log(this.gender);
  }
}

class Person extends Human {
  name = "Tina";
  gender = "Female";
  
  printName = () => {
    console.log(this.name);
  }
}

const myPerson = new Person();
console.log(myPerson.name);
myPerson.printName();
myPerson.printGender();
```
output

```
"Tina"
"Tina"
"Female"
```