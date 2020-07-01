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
- It is better to have more stateless(presentationa/ dump )components than stateful, they make apps easier to manage.

## Passing methods as references b/w components

- The function can be passed as refernce in form of property in the component, as property_name = {this.functionHandler}
- The property after being passed is used as props in component.
- Thus we can pass methods as props, to call this method that changes state in another component which does not have direct access to the state(such as the child component changing state present in Parent component). 

### Passing var to func from components

- 1st method: for this we can use **bind**
```js
onClick={this.switchNameHandler.bind(this, 'var_to_pass')}
```
```js
<button onClick={this.switchNameHandler.bind(this, "tina")}> Switch Name</button>
```
- 2nd method: using arrow functions
```js
<button onClick={() => this.switchNameHandler("tina")}> Switch Name</button>
```
- It is recommneded to use **bind**, cause with arrow function react might rerender things, and can be ineffecient.

## Two way Binding (dynamic rendering elemets)
- In App.js
```js
class App extends Component {
  state = {
    persons: [
       { name: 'A', age: 28},
       { name: 'B', age: 28},
       { name: 'C', age: 28},
    ],
    otherstate: 'Some state'
  }

  switchNameHandler = (newName) =>{
    console.log("Hello button works!");
    this.setState({
        persons: [
           { name: newName, age: 28},
           { name: 'B1', age: 28},
           { name: 'C1', age: 28},
        ] 
    })
    
  }

  nameChangeHandler = (event) => {
    this.setState({
        persons: [
           { name: 'A1', age: 28},
           { name: 'B1', age: 28},
           { name: event.target.value, age: 28},
        ] 
    })
  }

  render() {
    return (
      <div className="App">
        <h1>Hi this is a react app!</h1>
        <button onClick={() => this.switchNameHandler("tina")}> Switch Name</button>
        <Person 
          name={this.state.persons[0].name}
          age={this.state.persons[0].age}
          click={this.switchNameHandler}
          />
        <Person name={this.state.persons[1].name} age={this.state.persons[1].age}>Something I would do with this</Person>
        <Person 
          name={this.state.persons[2].name}
          age={this.state.persons[2].age}
          change={this.nameChangeHandler}/>
      </div>
    );
    //return React.createElement('div', React.createElement('h1',null, 'Hello World!'));
  }
}

export default App;

```
- In Person.js

```js
const person = (props) => {
  return(
    <div>
        <p onClick={ props.click }> I am a { props.name } and { props.age } years old!</p>
        <p>{ props.children }</p>
        <input type="text" onChange={ props.change } value={ props.name }/>
    </div>
  )
};

export default person;
```

## Add Styling
- add as const variable holding css
```js
render() {
    const style = {
      backgroundColor: 'green',
      font: 'inherit',
      border: '1px solid white',
      padding: '8px',
      cursor: 'pointer'
    }
    return (
      <div className="App">
        <h1>Hi this is a react app!</h1>
        <button style={style} onClick={() => this.switchNameHandler("tina")}> Switch Name</button>

```` 
- Add style={variable_storing_styles}
```js
<button style={style} />
```