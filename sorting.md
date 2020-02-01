# Sorting Algos

## Bubble Sort

* Idea
Checking pair of adjacent elements, swap if they occur in wrong order

* Code
```c++
void bubble sort(int A[], int n){
	int temp;
	for(int i = 0; i < n-1; i++){
	  // (n-k-1) is for ignoring comparisons of elements which were already compared
	  for(int j = 0; j < n-i-1; j++){
	    if(A[j]<A[j+1]){
	      temp = A[i];
	      A[i] = A[i+1];
	      A[i+1] = temp;
	    }
	  }
    }
}
```

* Complexity
O(n^2)

## Selection Sort

* Idea
Finding the min or max in unsorted ad puting in right posistion in sorted

* Code
```c++
void selection sort(int A[], int n ){
	int min;
	for(int i =0; i < n-1; i++){
	  min = i;
	  for(int j = i+1; j < n; j++){
	    if(A[j]< A[min]){
	      min = j;
	    }
	  }
	  swap(A[min], A[i]);
    }
}
```

* Complexity
finding min in N elements => n comparisons, array reduced to n-1 (1 element placed at sorted positions)
n-1 elements => n-2 comparisons
(n-1)+(n-2)+(n-3)+-----+1 = n*(n-1)/2
**O(n^2)**

## Insertion Sort

* Idea
One element from input elements is consumed in each iteration to find its correct position, position where it belongs in sorted array.

* Code
```c++
void insertion sort(int A[], int n ){
	for(int i =0; i < n; i++){
	  temp = A[i];
	  int j = i;
	  while(j > 0 && temp < A[j-1]){
	    A[j] = A[j-1];
	    j = j-1;
	  }
	  A[j] = temp;
    }
}
```

* Time Complexity
Worst case: Decreasing Order into increasing order
Best Case: Input already sorted in increasing order
**O(n^2)**
* Space Complexity
O(1)
* Uses
When number of elements small, or most of the elements are soreted

## Counting Sort

* Idea
Store frequency of distinct elements and stored in auxiliary array, by mapping value as an index of the auxiliary array. 

* Code
```c++
void counting_sort(int A[], int Aux[], int sortedA[], int n){
	int K =0;
	for(int i =0; i < n; i++){
	  k = max(k, A[i]);
    }

    for(int i =0; i<=k; i++){
      Aux[A[i]]++;
    }

    int j =0;

    for(int i =0; i<=k; i++){
      int tmp = Aux[i];
      while(tmp --){
        sorted[j] = i;
        j++;
      }
    }
}
```
* Complexity
O(N+K)

## Radix Sort

* Idea
Store frequency of distinct elements and stored in auxiliary array, by mapping value as an index of the auxiliary array. 

* Code
```c++
void counting_sort(int A[], int Aux[], int sortedA[], int n){
	int K =0;
	for(int i =0; i < n; i++){
	  k = max(k, A[i]);
    }

    for(int i =0; i<=k; i++){
      Aux[A[i]]++;
    }

    int j =0;

    for(int i =0; i<=k; i++){
      int tmp = Aux[i];
      while(tmp --){
        sorted[j] = i;
        j++;
      }
    }
}
```
* Complexity
O(N+K)

## Merge Sort

* Idea
Breaking down list into sublist until each sublist consist of one element and then merging in such a way that it results in a sorted list.

* Code
```c++
void merge (int A[], int start, int mid, int end){
	int p = start, q = mid+1;
	int Arr[end-start+1], k =0;

	for(int i = start, i<=end; i++){
		if(p>mid){
			Arr[k++] = A[q++];
		}
		else if(q>end){
			Arr[k++] = A[p++];
		}
		else if (A[p] < A[q]){
			Arr[k++] = A[p++];
		}
		else 
			Arr[k++] = A[q++];
	}
	for(int p =0; p<k ; p++){
		A[start+++] = Arr[p];
	}
}
void merge_sort(int A[], int start, int end){
	if(start < end) {
		int mid = (start+end) /2;
		merge_sort(A, start, mid);
		merge_sort(A, mid+1, end);

		merge(A, start, mid, end);
	}
}
```
* Complexity
list of N divided into max of LogN parts and then merging into single takes O(N) time
O(NLogN)
[check this out lol](https://stackoverflow.com/questions/24594112/when-will-the-worst-case-of-merge-sort-occur)

## Quick Sort

* Idea
Breaking down list into sublist until each sublist consist of one element and then merging in such a way that it results in a sorted list.

* Code
```c++
int partition (int A[], int start, int end){
	int i = start+1;
	int piv = A[start];
	for(int j = start+1; j<=end; j++){
		if(A[j] < piv)
			swap(A[i], A[j]);
		i++;
	}
	swap(A[start, A[i-1]]);
	return i-1;
}
void quick_sort(int A[], int start, int end){
	if(start < end) {
		int piv_pos = partition (A, start, end);
		quick_sort(A, start, piv_pos-1);
		quick_sort(A, piv_pos+1, end);
	}
	merge(A, start, mid, end);
}
```
using rand_partition() instead of partition() to reduce time complexity

```c++
int rand_partition(int A[], int start, int end){
	int random = start+rand() % (end-start+1);
	swap(A[random, A[start]]);
	return partition(A, start, end);
}
```
* Complexity
worst case O(N^2), with randomised the complexity fluctuates between O(N^2) to O(NlogN)


