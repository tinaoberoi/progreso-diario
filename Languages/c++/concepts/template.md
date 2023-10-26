# Templates

* Template in c++ is a feature.
* write code once and use it for any data type (including user defined data types)
* Example: sort(), for sorting any data type items.

```c++
template <class T>
void sort(T arr[], int size){
	// code to implement sort
}
```
* *What if we want diff code for particular data type ?*

ex: Quick sort for all and counting sort for char

```c++
template <class T>
void sort(T arr[], int size){
	// code to implement quick sort
}

template <>
void sort<char>(char arr[], int size){
	// code to implement counting sort
}

```  
## Template speacialization

```c++
#include <iostream>
using namespace std;

template <class T>
class Test
{
public: 
	Test()
	{
		cout<< "General template \n";
	}
};

template <>
class Test<int>
{
public:
	Test()
	{
		cout<<"Specialized template\n";
	}
};
int main()
{
	Test<int> a;
	Test<char> b;
	Test<float> c;
	return 0;
}
```

> *Output*
> Specialized template
> General template 
> General template
### How does template specialization works ?

When we write any template based function or class, compiler creates a copy of that function/class whenever compiler sees that being used for a new data type or new set of data types. 
If a specialized version is present, compiler first checks with specialized version and then the main template. Compiler first checks with the most specialized version by matching the passed parameter with the data types specified in the specialized version.
