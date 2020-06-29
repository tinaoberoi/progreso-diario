- Now numbers, strings, booleans these are so-called primitve types whenever you reassign or you store a var in another var, it will copy the value

```js
const number = 1;
const number2 = number;
console.log(number2);
```
Output
```
1
```
This created a copy of number and stored as number2

- Objects and arrays are reference types. 

```js
const person = {
  name: "Tina"
}
const newPerson = person;

console.log(newPerson);
````
Ouput

```
[object Object] {
  name: "Tina"
}
```
Here person is not copied. The object is stored in memory and in the const person we store a pointer to that place in memory. And if we then assign person to newPerson that pointer will be copied.

```js
const person = {
  name: "Tina"
}
const newPerson = person;
person.name = "Max";
console.log(newPerson);
```
Output
```
[object Object] {
  name: "Max"
}
```
- We need a way to copy the object and not just the pointer, thus we use spread operator

```js
const person = {
  name: "Tina"
}
const newPerson = {
  ...person
}
person.name = "Max";
console.log(newPerson);
```
Output

```
[object Object] {
  name: "Tina"
}
```
