# List and Conditionals

## Rendering content conditionally
- We cannot write if else (block code)
- But we can use jsx and add simple javascript
```js
class App extends Component {
  state = {
  	persons: [
  	   { name: 'A', age: 28},
  	   { name: 'B', age: 28},
  	   { name: 'C', age: 28},
  	],
  	otherstate: 'Some state',
    showPerson: false
  }

  togglePersom = () => {
    const status = this.state.showPerson;
    this.setState({
      showPerson : !status
    })
  }

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
        <button style={style} onClick={this.togglePersom}> Show Person</button>
        { this.state.showPerson === true ? 
          <Person 
            name={this.state.persons[1].name} 
            age={this.state.persons[1].age}>
            Something I would do with this
          </Person>
          : null
        }
        <Person 
          name={this.state.persons[2].name}
          age={this.state.persons[2].age}
          change={this.nameChangeHandler}/>
      </div>
    );
  }
}

export default App;

```
- The jsx { this. ? a : b} could be confusing especially nest .
- when react renders it executes not only the return but everything inside render method.
- creating a variable nad using if else inside render (here i can write js)

```js
class App extends Component {
  state = {
  	persons: [
  	   { name: 'A', age: 28},
  	   { name: 'B', age: 28},
  	   { name: 'C', age: 28},
  	],
  	otherstate: 'Some state',
    showPerson: false
  }

  render() {

    let person = null;
    if(this.state.showPerson){
      person = (
        <Person 
          name={this.state.persons[1].name} 
          age={this.state.persons[1].age}>
          Something I would do with this
        </Person>
      );
    }

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
        <button style={style} onClick={this.togglePersom}> Show Person</button>
        { person }
      </div>
    );
    //return React.createElement('div', React.createElement('h1',null, 'Hello World!'));
  }
}

```

## Outputing Lists

- Looping through list : map fucntion
```js
class App extends Component {
  state = {
    persons: [
       { name: 'A', age: 28},
       { name: 'B', age: 28},
       { name: 'C', age: 28},
    ],
    otherstate: 'Some state',
    showPerson: false
  }

  render() {
    let person = null;
    if(this.state.showPerson){
      person = (
        <Person 
          name={this.state.persons[1].name} 
          age={this.state.persons[1].age}>
          Something I would do with this
        </Person>
      );
    }

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
        <button style={style} onClick={this.togglePersom}> Show Person</button>
        {this.state.persons.map(person => {
          return <Person name={person.name} age={person.age}/>
        })}
      </div>
    );
  }
}

```
- Manipulating the array: 

```js
class App extends Component {
  state = {
    persons: [
       { name: 'A', age: 28},
       { name: 'B', age: 28},
       { name: 'C', age: 28},
    ],
    otherstate: 'Some state',
    showPerson: false
  }

  deletePersonHandler = (personIndex) =>{
    const persons = this.state.persons.slice();
    persons.splice(personIndex, 1);
    this.setState({persons: persons})
  }

  render() {
    return (
      <div className="App">
        {this.state.persons.map((person, index) => {
          return <Person click={() => this.deletePersonHandler(index)} name={person.name} age={person.age}/>
        })}
      </div>
    );
  }
}

export default App;
```
- Here we used index of map menthod to delete/modify the state of persons list. But there is a issue.

- In js objects and arrays are reference types
```js
const persons = this.state.persons;
    
```
- This creates a pointer and further mutates the actual data, this is a bad practice. The better approach would be to create a copy of the data and then manipulate it.
- Thus we should update the state in an immutable manner, create a copy, change and then update with state.
```js
const persons = [...this.state.persons];
persons.splice(personIndex, 1);
this.setState({persons: persons})
````
- They **key** prop is actually an important property we should add when rendering list of data. This key property helps react update the list efficiently.
- Using key, React makes sure when you update the list it rerenders only changed elemets and not the entire list. 
- key is unique
```js
```js
class App extends Component {
  state = {
    persons: [
       { name: 'A', age: 28},
       { name: 'B', age: 28},
       { name: 'C', age: 28},
    ],
    otherstate: 'Some state',
    showPerson: false
  }

  deletePersonHandler = (personIndex) =>{
    const persons = this.state.persons.slice();
    persons.splice(personIndex, 1);
    this.setState({persons: persons})
  }

  render() {
    return (
      <div className="App">
        {this.state.persons.map((person, index) => {
          return <Person click={() => this.deletePersonHandler(index)} name={person.name} age={person.age} key = { index }/>
        })}
      </div>
    );
  }
}

export default App;
```

### Deleting lists
- In App.js
```js
class App extends Component {

  state = {
    inputstring: "",
    inputlen : 0,
    statement: ""
  }

  changeInputHandler = (event) => {
    console.log(event.target.value);
    let s = event.target.value;
    if(s.length > 5){
      this.setState({statement: "Text long enough"});
    }else{
      this.setState({statement: "Text too short"});
    }
    this.setState({ inputstring: s });
    this.setState({ inputlen: s.length });

  }

  deleteHandler = (index) => {
    const text = this.state.inputstring.split('');
    text.splice(index, 1);
    const updatedText = text.join('');
    this.setState({inputstring: updatedText});
  }
  
  render() {
    
    

    const list = [...this.state.inputstring];
    const listMap = list.map((s, index) => { 
      return <CharComponent letter={s} index={index} click={() => this.deleteHandler(index)}/>
    });
    
    
    return (
      <div className="App">
        <h1>Hello World!</h1>
        <input onChange={ this.changeInputHandler }/>
        <ValidationComponent len={this.state.inputlen} s={this.state.statement}/>
        <CharComponent />
        {listMap}
      </div>
    );
  }
}

export default App;

````
- In Char.js
```js
import React, { Component } from 'react';

const CharComponent = (props) => {
  const style = {
      display: 'inline-block',
      border: '1px solid black',
      padding: '16px',
      textAlign: 'center',
      margin: '16px',
      color: 'green',
      backgroundColor: 'blue'
    };
  return (
    <div style={style} onClick = {props.click} >
       <p>{props.value}: {props.letter} </p>
    </div> 
  )
};

export default CharComponent;
```