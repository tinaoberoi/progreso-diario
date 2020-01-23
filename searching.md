 Searching Algos

## Linear Search

* Idea
Basic

* Code
```c++
for(start to end of array){
	if(curr == to_find){
		return curr;
	}
}
```

* Complexity
O(n)

## Binary Search

* Idea
Basic

* Code
```c++
int binary_search(int low, int high, int key){
	while(low<=high){
		int mid = (low+high)/2;
		if(a[mid]<key){
			low=mid+1;
		}else if(a[mid] > key){
			high = mid-1;
		}else{
			return mid;
		}
	}
	return -1;
}
```

* Complexity
O(log<sub>2</sub>(n))