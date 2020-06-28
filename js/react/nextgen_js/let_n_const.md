# Let and Const

- let and const are different ways of creating variables
- earlier only *var* was used in js, but now with es6 we have let and cost as options.(though var still works)
- let = variable values and const = constant values

```js
var myName = "Ana";
console.log(myName);

myName = "tina";
console.log(myName);


let myName2 = "Ana2";
console.log(myName2);

myName2 = "tina2";
console.log(myName2);

//error
const myName3 = "Ana3";
console.log(myName3);

myName3 = "tina3";
```
output

```
"Ana"
"tina"
"Ana2"
"tina2"
"Ana3"
"error"
"TypeError: Assignment to constant variable.
    at pohacizoju.js:17:9
    at https://static.jsbin.com/js/prod/runner-4.1.7.min.js:1:13924
    at https://static.jsbin.com/js/prod/runner-4.1.7.min.js:1:10866"
```