/*https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-all-elements-are-k-distance-apart/*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[], int n, int k, int i){
	int max_sum = INT_MIN, max_ending_here = 0;

	while(i<n){
		max_ending_here += arr[i];
		if(max_ending_here > max_sum){
			max_sum = max_ending_here;
		}
		i+=k;
	}
	return max_sum;
}

int find(int arr[], int n, int k){
	int max_sum = 0;
	for(int i =0; i<(min(k, n); i++)){
		max_sum = max(max_sum, maxSubArraySum(arr, n, k, i));
	}
	return max_sum;
}

int main(){
	int arr[] = { 2, -3, -1, -1, 2 }; 
	int n = sizeof(arr)/sizeof(arr[, 0]);
	int k = 2;
	cout<<find(arr, n , k);
}