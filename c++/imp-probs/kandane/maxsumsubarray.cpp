#include<bits/stdc++.h>
using namespace std;

int maxSumSubArray(vector<int> &A){
	int n = A.size();
	int global_max = INT_MIN;
	int local_max = 0;

	for(int i =0; i<n; i++){
		local_max = max(A[i], local_max+A[i]);
		if(local_max>global_max){
			global_max = local_max;
		}
	}
	return global_max;
}