import React, { Component } from 'react';
import './App.css';
import Person from './Person/Person';
class App extends Component {
  state = {
  	persons: [
  	   { name: 'A', age: 28},
  	   { name: 'B', age: 28},
  	   { name: 'C', age: 28},
  	],
  	otherstate: 'Some state'
  }

  switchNameHandler = () =>{
  	console.log("Hello button works!");
  	this.setState({
  	    persons: [
  	       { name: 'A1', age: 28},
  	       { name: 'B1', age: 28},
  	       { name: 'C1', age: 28},
  	    ]	
  	})
  	
  }

  render() {
    return (
      <div className="App">
        <h1>Hi this is a react app!</h1>
        <button onClick={this.switchNameHandler}> Switch Name</button>
        <Person name={this.state.persons[0].name} age={this.state.persons[0].age}/>
        <Person name={this.state.persons[1].name} age={this.state.persons[1].age}>Something I would do with this</Person>
        <Person name={this.state.persons[2].name} age={this.state.persons[2].age}/>
      </div>
    );
    //return React.createElement('div', React.createElement('h1',null, 'Hello World!'));
  }
}

export default App;
