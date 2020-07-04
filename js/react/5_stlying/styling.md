# Styling Components and Elements

## Outline
- We do not use pseudo selectors in the inline styling method we used earlier, though we can use the css file, to add these property (like button: hover). But the problem is when we need only one button to behave some sort of way when hovered.

- Changing styles dynamically (Eg: Green background when add and Red background when delete)

## Setting Styles Dynamically

- just as any variable we can change the style properties dynamically.

- The style variable property is changed in the if-else block.

```js
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
        <p>this is working</p>
        <button style={style} onClick={this.togglePersom}>Toggle Presons</button>
        {persons}
      </div>
    );
  }
}

export default App;

```
## Setting Class Names Dynamically

- simple js if-else count work, make a variable className and assign it value

```js
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
      classes.push('red'); // red
    }
    if(this.state.persons.length <=1){
      classes.push('bold'); // red and bold
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
```
- Since className accepts string we used .join('')

## Limitations of inline styles

- No pseudo selectors, Eg: we cannot assign hover to buttons.

- Fix: styling the button with css file only, but this style would not be scoped for this component only, but all the buttons in our application would get. Though we could work with some unique csids

### How to use pseudo selectors and media queries in inline styles 

- Solution: Radium
- Now I can use **hover**
```js
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
      cursor: 'pointer',
      ':hover': {
        backgroundColor: 'lightgreen',
        color: 'black'
      }
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
      style[':hover'] = {
        backgroundColor : 'salmon',
        color : 'black'
      }
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

```

### Media Queries using radium
- same as hover, but we have to inlcude StyleRoot from Radium
In Person.js
```js
const person = (props) => {
	const style  = {
		'@media (min-width: 500px)': {
			width: '450px'
		}
	}

	return(
		<div className="Person" style={style}>
		    <p onClick={ props.click }> I am a { props.name } and { props.age } years old!</p>
		    <p>{ props.children }</p>
		</div>
	)
};

```
In App.js
```js
import Radium, { StyleRoot } from 'radium';

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
      cursor: 'pointer',
      ':hover': {
        backgroundColor: 'lightgreen',
        color: 'black'
      }
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
      style[':hover'] = {
        backgroundColor : 'salmon',
        color : 'black'
      }
    }
    return (
    <StyleRoot>
      <div className="App">
        <h1>React App</h1>
        <p className={classes.join(' ')}>this is working</p>
        <button style={style} onClick={this.togglePersom}>Toggle Presons</button>
        {persons}
      </div>
    </StyleRoot>
    );
  }
}

export default Radium(App);

```

## Another popular package is Styled components library
- Styled Components, all html tags present here as methods
- This css we add is not added as inline but in the head
```js
const StyledDiv = style.div`
                    // css goes here
                   `;
 ......
       render(){
       	return(
       		<StyledDiv>
       		   ...
       		</StyledDiv>
       	);
       }
```