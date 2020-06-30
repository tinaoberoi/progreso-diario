# Destructuring

- Easily allows array elements or objects prop and store them in var
- It is diff from spread, as spread takes out all properties and distributes them in a new array or object whereas destructuring allows you to pull out single elements or prop and store them in var for arrays and objects
- Array destructuring, [a, b] = ["Hello", "Max"]
- console.log(a) //Hello and console.log(b) // Max
- Object Destructuring, {name} = {name: 'Max', age: 28}
- console.log(name) // Max and console.log(age) //undefined
```js
const numbers = [1, 2, 3];
[num1, num2] = numbers;

console.log(num1);
console.log(num2);

```
```
1
2
```

```js
const numbers = [1, 2, 3];
[num1, ,num3] = numbers;

console.log(num1);
console.log(num3);
```
```output
1
3
```
