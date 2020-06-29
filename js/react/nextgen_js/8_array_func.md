# Array Func

- map() function takes array as input and then this func is exec on each element in the array

```js

const numbers = [1, 2, 3];

const doubNum = numbers.map((x) => {
  return x*2
});
console.log(numbers)
console.log(doubNum);
```
Output
```
[1, 2, 3]
[2, 4, 6]
```
- find(), The find() method returns the value of the first element in the provided array that satisfies the provided testing function.

```js
const numbers = [1, 2, 3];

const doubNum = numbers.find((x) => {
  return x>1
});
console.log(numbers)
console.log(doubNum);
```
Output
```
[1, 2, 3]
2
```
- The **findIndex()** method returns the index of the first element in the array that satisfies the provided testing function. Otherwise, it returns -1, indicating that no element passed the test.

```js

const numbers = [1, 2, 3];

const doubNum = numbers.findIndex((x) => {
  return x>1
});
console.log(numbers)
console.log(doubNum);
```
output
```
[1, 2, 3]
1
```
- The reduce() method executes a reducer function (that you provide) on each element of the array, resulting in single output value.

```js
const array1 = [1, 2, 3, 4];
const reducer = (accumulator, currentValue) => accumulator + currentValue;

// 1 + 2 + 3 + 4
console.log(array1.reduce(reducer));
// expected output: 10

// 5 + 1 + 2 + 3 + 4
console.log(array1.reduce(reducer, 5));
// expected output: 15

```
- The concat() method is used to merge two or more arrays. This method does not change the existing arrays, but instead returns a new array.

```js
const array1 = ['a', 'b', 'c'];
const array2 = ['d', 'e', 'f'];
const array3 = array1.concat(array2);

console.log(array3);
// expected output: Array ["a", "b", "c", "d", "e", "f"]

```

- The slice() method returns a shallow copy of a portion of an array into a new array object selected from start to end (end not included) where start and end represent the index of items in that array. The original array will not be modified.

```js
const animals = ['ant', 'bison', 'camel', 'duck', 'elephant'];

console.log(animals.slice(2));
// expected output: Array ["camel", "duck", "elephant"]

console.log(animals.slice(2, 4));
// expected output: Array ["camel", "duck"]

console.log(animals.slice(1, 5));
// expected output: Array ["bison", "camel", "duck", "elephant"]

```
- The splice() method changes the contents of an array by removing or replacing existing elements and/or adding new elements in place.

```js
const months = ['Jan', 'March', 'April', 'June'];
months.splice(1, 0, 'Feb');
// inserts at index 1
console.log(months);
// expected output: Array ["Jan", "Feb", "March", "April", "June"]

months.splice(4, 1, 'May');
// replaces 1 element at index 4
console.log(months);
// expected output: Array ["Jan", "Feb", "March", "April", "May"]
```