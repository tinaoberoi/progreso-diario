# Macros

* Lines with # are preprocessed by preprocessor. 
* *include* directive, contents of included header file are copied (after preprocessing)
* *define* for a constant
* macros take fucntion like arguments, the arguments are not checked for data type.
```c++
#include <stdio.h>
# define INCREMENT(x) ++x;

int main(){
	char *ptr = "GeeksQuiz"
	int x = 10;
	printf("%s ", INCREMENT(ptr));
	printf("%s ", INCREMENT(x) );
	return 0;
}
```
> **Output**
> eeksQuiz 11