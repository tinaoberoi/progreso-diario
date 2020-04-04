# Disjoint Data Structures

* Data Structure that keeps track of a set of elements partitioned into number of disjoint subsets (non-overlapping subsets)
* union-find algorithm is an algorithm that performs 2 useful operations on a data structure, union and find.
* **Find:** Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
* **Union:** Join two subsets into a single subset.
* Helps reducing exec time of algorithm
* Useful in graphs to connect nodes or finding connected components

```c++
//finding root of an element
void initialize (int Arr[], int N){
	for(int i =0; i<N; i++){
		Arr[i] = i;
		size[i] = 1;
	}
}

int root(int Arr[], int i){
	while(i != Arr[i]){ //chase parent of curr element until it reaches root
		i = Arr[i];
	}
	return i;
}
/*
int func_union(int Arr[], int A, int B){
	int root_A = root(Arr, A);
	int root_B = root(Arr, B);

	Arr[root_A] = root_B; // setting parent of root(A) as root(B)
}
*/

void weighted_union(int Arr[], int size[], int A, int B){
	int root_A = root(A);
	int root_B = root(B);
	if(size[root_A] < size[root_B]){
		Arr[root_A] = root_B;
		size[root_B]+=size[root_A];
	}else{
		Arr[root_B] = root_A;
		size[root_A] += size[root_B];
	}
}

bool find(int A, int B){
	if(root(A) == root(B))
		return true;
	else
		return false;
}
```

* Complexity of weighted_union O(logn) :