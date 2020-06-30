- {} can be used to call functions like 
```js
{Math.floor(Math.random())}
```

## For dynamic components

- For this we can use props
- Passing var in to components
```js
<Person name = "Tina" age = "23" />
```
- And using it in components

```js
const person = (props) => {
	I am {props.name} and {props.age} years old!
};
```
**Refer props.pdf**

- **children** refers to any component b/w opening and closing tag.
- here children refers to anytext, plaintext, ordered list, multi-list item etc.
```js
//In App.js
<Person name = "Tina" age = "23" >I love dancing too</Person>
```


```js
//In person.js
const person = (props) => {
	return (
		<p>I am {props.name} and {props.age} years old!</p>
		<p>{ props.children }</p>
	)
};
```

## States in Components

- states are only available in components.
- props are set from outside like name and age in person component, state is managed inside the component 
```js
class App extends Component {
  state = {
  	persons: [
  	   { name: 'A', age: 28},
  	   { name: 'B', age: 28},
  	   { name: 'C', age: 28},
  	]
  }
  render() {
    return (
      <div className="App">
        <h1>Hello World!</h1>
        <Person name={this.state.persons[0].name} age={this.state.persons[0].age}/>
        <Person name="B" age="21">Something I would do with this</Person>
        <Person name="C" age="22"/>
      </div>
    );
    //return React.createElement('div', React.createElement('h1',null, 'Hello World!'));
  }
}

```
- If the state changes it lead React to re-render our DOM or to update the DOM.

## Handling Events

- the Handler at the end of function indicates that this is a method you are not actively calling but you are assigning as an event handler.
- For writing a event handler 
```js
{ this.funcname }
```
- Dont do this, this will exec it immediately once react render this to the dom because you exec this func. 
```js
{ this.function() }
```
- For event handler we only want to pass a refernce and we do this by using {this.funcname}

```js
class App extends Component {
  state = {
  	persons: [
  	   { name: 'A', age: 28},
  	   { name: 'B', age: 28},
  	   { name: 'C', age: 28},
  	]
  }

  switchNameHandler = () =>{
  	console.log("Hello button works!");
  }

  render() {
    return (
      <div className="App">
        <h1>Hi this is a react app!</h1>
        <button onClick={this.switchNameHandler}> Switch Name</button>
        <Person name={this.state.persons[0].name} age={this.state.persons[0].age}/>
        <Person name="B" age="21">Something I would do with this</Person>
        <Person name="C" age="22"/>
      </div>
    );
    //return React.createElement('div', React.createElement('h1',null, 'Hello World!'));
  }
}

```
## Mutating state

- We shouldn't mutate the state directly like this,

```js
this.state.person[0].name = "Some other name";
```
- Rather use **component's** provided method **setstate**
```js
this.setState({ })
```` 

## React Hooks for states

- setState feature is only available in class based components, Prior to React 16.8 this was the only way to manage state.
- After 16.8, we also have React Hooks
- useState Hook allows us to manage state, we call it like a function
- **this** keyword is wrong as we are not in class anymore.
```js
import { useState } from 'react';

const app = () => {
  
  const [personState, setPersonState] = useState({
    persons: [
       { name: 'A', age: 28},
       { name: 'B', age: 28},
       { name: 'C', age: 28},
    ]
  });

  const switchNameHandler = () =>{
    setPersonState({
       { name: 'A1', age: 28},
       { name: 'B1', age: 28},
       { name: 'C1', age: 28},  
    )}
  }

    return (
      <div className="App">
        <h1>Hi this is a react app!</h1>
        <button onClick={switchNameHandler}> Switch Name</button>
        <Person name={personState.persons[0].name} age={personState.persons[0].age}/>
      </div>
    );
    //return React.createElement('div', React.createElement('h1',null, 'Hello World!'));
}

```
- you can use any number of useSate.