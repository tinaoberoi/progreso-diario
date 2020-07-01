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