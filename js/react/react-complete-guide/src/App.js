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
  	otherstate: 'Some state',
    showPersons: false
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

  togglePersom = () => {
    const status = this.state.showPersons;
    this.setState({
      showPersons : !status
    })
  }

  deletePersonHandler = (personIndex) =>{
    const persons = this.state.persons.slice();
    persons.splice(personIndex, 1);
    this.setState({persons: persons})
  }

  render() {
    const style = {
      backgroundColor: 'green',
      color: 'white',
      font: 'inherit',
      border: '1px solid blue',
      padding: '8px',
      cursor: 'pointer'
    };

    const classes = [];
    if(this.state.persons.length <= 2){
      classes.push('red');
    }
    if(this.state.persons.length <=1){
      classes.push('bold');
    }

    let persons = null;

    if(this.state.showPersons) {
      persons = (
        <div>
          {this.state.persons.map ((person, index) => {
            return <Person 
               click = {() => this.deletePersonHandler(index)}
               name = {person.name}
               age = {person.age}
               key = {index}
               changed = {(event) => this.nameChangeHandler(event)}
            />
          })}
        </div>
      );
      style.backgroundColor = 'red';
    }
    return (
      <div className="App">
        <h1>React App</h1>
        <p className={classes.join(' ')}>this is working</p>
        <button style={style} onClick={this.togglePersom}>Toggle Presons</button>
        {persons}
      </div>
    );
  }
}

export default App;
