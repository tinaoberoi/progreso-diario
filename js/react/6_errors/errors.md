# Errors

- componentDidCatch is a method that receives potenctial error and add some additional info passed into it automatically by react and. It will be exec whenever the component we wrap with the error boundary throws an error 

```js
import React, { Component } from 'react';

class ErrorBoundary extends Component {
	state = {
		hasError: false,
		errorMessage: ''
	}

	componentDidCatch = (error, infor) => {
		this.setState({hasError: true, errorMessage: error});
	}

	render() {
		if (this.state.hasError) {
			return <h1>{this.state.errorMessage}</h1>
		} else {
			return this.props.children;
		}
	}
}

export default ErrorBoundary;
````  
- That does not mean you cluster your whole application with error bounderies,only use them if you have some code that you know it may fail.