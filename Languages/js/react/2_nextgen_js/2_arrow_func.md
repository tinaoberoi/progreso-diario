# Arrow Func

A normal js func looks like 

```js
function myFnc(parameters){
	...
}


var myfunc = function (a, b){return a*b};
````
But an arrow function looks like this

```js
const myFunc = () => {
	...
}
```

```js

function printName(name){
  console.log(name);
}

printName("Max");

const printName2 = (name) => {
  console.log(name);
}

printName2("Ana");

let printName3 = (name) => {
  console.log(name);
}

printName3("Tina");
```
Output

```
"Max"
"Ana"
"Tina"
```

```js
const multiply = (num) => {
  return num*2;
}

console.log(multiply(2));

const multiply2 = (num) => num*2;

console.log(multiply2(2));
```
output

```
4
4
```

Benefits of arrow function:
- No more issues with *this* keyword
