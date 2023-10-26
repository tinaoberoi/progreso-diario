/*
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
Output
For each test case print the required answer in a seperate line.
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9
*/
/*
Think using min heap and fnd out the probelm
Hint: doesnot work if k>n
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<ll> A,ll n, ll mid, ll k){
    ll sum = 0;
    for(ll i =0; i<n; i++){
        sum+=A[i]/mid;
    }
    if(sum>=k){
        return true;
    }
    return false;
}

ll binary_search(vector<ll> A, ll n, ll k){
    ll ans = 0;
    ll low = 0, high = A[n-1];
    while(low<=high){
      ll mid = low + (high-low)/2;
      if(check(A, n, mid, k)){
          low = mid+1;
          if(mid > ans)
            ans = mid;
      }else{
          high = mid-1;
      }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> A(n);
        for(ll i =0; i<n; i++){
            cin>>A[i];
        }
        sort(A.begin(), A.end());
        cout<<binary_search(A, n, k)<<endl;
    }   
    return 0;
}