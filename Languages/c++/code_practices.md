# Best Practices for efficient code

* Use range base for loop
```c++
int main(){
	vector<int> v = {0, 1, 2, 3, 4};

	for(const auto &val : vec)
		cout<<val<<" ";

	cout<<'\n';
    
    int arr[] = {1, 2, 3, 4, 5};
	for(const auto &val : arr)
		cout<<val<<" ";
}
```
> **Output**
> 0 1 2 3 4
> 1 2 3 4 5

* Initializer list
used to access values in c++ initialization list. Here objects of this type are automatically constructed by compiler from initialization list declearations, which is a list of coma separated elements in braces.

```c++
#include <iostream>

template<typename T>
void printList(std:: initializer_list<T> text)
{
	for(const auto &val : text)
		cout<<val<<" ";
} 

int main(){
	printList({"one", "two"});
	return 0;
}
```
> **Output**
> one two

* Using macros for loops

```c++
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(i =0; i<n; i++)
#define REP(i, k, n) for(i =k; i<=n; i++)

int main(){
	int i;
	int array[] {4, 5, 6, 9 , 11, 12};
	int size = sizeof(array)/sizeof(array[0]);

	rep(i, size)
	    cout<<array[i]<<" ";

    cout<<"\n";

	REP(i, 1, size-1)
	    cout<<array[i]<<" ";

	return 0;
}
```
> **Output**
> 4 5 6 8 11 12
> 5 6 8 11 12