# Exports and Imports

- js support modules, split code into multiple files

```js
//person.js
const person = () =>{
	name: 'Max';
}
export default person
```

```js
//utility.js
export const clean = () => {...}
export const baseData = 10;
```

```js
//app.js

//here i may name the import person or prs does not matter
import person from './person.js'
import prs from './person.js'

import {baseData} from './utility.js'
import {clean} from './utility.js'
```

- when we have default export ypu can choose the name
- but if we have a named export we have to have the exact name as defined in the file

```js
import { smth } from './utility.js'
import { smth as Smth } from './utility.js'
```
- import all 

```js
import * as bundled from './utility.js'
```