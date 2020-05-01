#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxLen 10 
int dp[maxLen]; 
bool v[maxLen];

int maxCount(vector<int> arr, int i, int n) 
{ 
    // Base case 
    if (i >= n) 
        return 0; 
  
    // To check if a state has 
    // been solved 
    if (v[i]) 
        return dp[i]; 
    v[i] = 1; 
  
    // Required recurrence relation 
    dp[i] = max(maxCount(arr, i + 1, n), 
                1 + maxCount(arr, i + 2, n)); 
  
    // Returning the value 
    return dp[i]; 
} 

vector<int> helper(vector<int> v, int n, int type){
	vector<int> res(n, -1);
	for(int i =0; i<n; i++){
		if(v[i] == type){
			res[i] = v[i];
		}
	}
	return res;
}

int chefNnum(vector<int> v, int n){
	vector<int> v1 = helper(v, n, 1);
	vector<int> v2 = helper(v, n, 2);
	int count_1 = maxCount(v1, 0, n);
	int count_2 = maxCount(v2, 0, n);

	int ans = ((count_2 > count_1) ? 2 : 1);

	return ans;
}

int main(){
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		vector<int>v(n);
		for(int i =0; i<n; i++){
			cin>>v[i];
		}
		cout<<chefNnum(v, n)<<endl;    
	}
	return 0;
}