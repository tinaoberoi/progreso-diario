# Sorting Algos

## Bubble Sort

* Idea
Checking pair of adjacent elements, swap if they occur in wrong order

* Code
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

* Complexity
O(n^2)
---

## Selection Sort

* Idea
Finding the min or max in unsorted ad puting in right posistion in sorted

* Code
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

* Complexity
finding min in N elements => n comparisons, array reduced to n-1 (1 element placed at sorted positions)
n-1 elements => n-2 comparisons
(n-1)+(n-2)+(n-3)+-----+1 = n*(n-1)/2
**O(n^2)**
---

## Insertion Sort

* Idea
One element from input elements is consumed in each iteration to find its correct position, position where it belongs in sorted array.

* Code
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


* Complexity
**O(n^2)**

---

## Counting Sort

* Idea
Store frequency of distinct elements and stored in auxiliary array, by mapping value as an index of the auxiliary array. 

* Code
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
* Complexity
O(N+K)

---

## Radix Sort

* Idea
Store frequency of distinct elements and stored in auxiliary array, by mapping value as an index of the auxiliary array. 

* Code
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
* Complexity
O(N+K)