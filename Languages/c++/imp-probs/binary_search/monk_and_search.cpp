/* 
(https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monk-and-search-2/description/)

Explaination:

lower_bound(x):
In binary search loop 
1. if(a[mid]>=x) answer would not exceed x, end = mid;
2. if(a[mid]<x) start = mid+1;

Pseudo Code:
int lower_bound(int start, int end, int item){
	while(start<end){
	  int mid = (end-start)/2 + start;

	  if(arr[mid]>=item){
	    end = mid;
	  }else{
	    start = mid+1;
	  }
	}
	return start;
} 
int upper_bound(int start, int end, int item){
	while(start<end){
	  int mid = start + (end-start)/2;
	  if(arr[mid]<=item){
	    start = mid+1;
	  }else
	    end = mid;
	}
	return start;
}

Time Complexity of each is Log(N)
*/

#include<bits/stdc++.h> 
using namespace std;

// Driver program 
int main() 
{ 
    int n, q;
    cin>>n;
    vector<int> vec(n);
    for(int i =0; i<n; i++){
    	cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    int bin, x, ans;
    cin>>q;
    while(q--){
    	int type, x;
    	cin>> type>>x;
    	if(!type){
    		cout<< (n-((int) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())))<<endl;
    	}else{
    		cout<< (n-((int)(upper_bound(vec.begin(), vec.end(), x) - vec.begin())))<<endl;
    	}
    }
    
    return 0; 
} 