/*
http://codeforces.com/problemset/problem/160/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	int total = 0;
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}
	for(int i =0; i<n; i++){
		total+=arr[i];
	}
	sort(arr.begin(), arr.end());
	int count = 0;
	int sum = 0;
	
	for(int i =n-1; i>=0; i--){
		sum+=arr[i];
		count++;
		total-=arr[i];
		if(sum > total){
			break;
		}
	}
	cout<<count<<endl;
	return 0;
}