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