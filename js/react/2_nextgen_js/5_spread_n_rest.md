# Spread and Rest Operators

## Spread
- Used to split up array elements OR object properties

```js
const newArray = [...oldArray, 1, 2]
const newObject = {...oldObject, newProp:5}
```

## Rest
- Used to merge a list of function arguments into an array

Here sortArgs receive any number of arguments, all these arguments merged together into an array
```js
function sortArgs(...args){
	return args.sort()
}
```
Example for array:
```js
const n = [1, 2, 3];
const nn1 = [...n, 4];
const nn2 = [n, 4]
console.log(n);
console.log(nn1);
console.log(nn2);
```
Output
```
[1, 2, 3]
[1, 2, 3, 4]
[[1, 2, 3], 4]
```

Example for object:
```js
const person = {
  name: "Max"
};

const newPerson = {
  ...person,
  age: 28
};

console.log(newPerson);
```
Ouput

```
[object Object] {
  age: 28,
  name: "Max"
}
```

```js
const filter = (...args) =>{
  return args.filter(el => el === 1)
}

console.log(filter(1, 2, 3, 1));
```
```
[1, 1]
```