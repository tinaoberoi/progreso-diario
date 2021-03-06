/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<ll> dist, ll mid, int n, int c){
    int count = 1;
    ll last_pos = dist[0];

    for(int i =1; i<n; i++){
        if(dist[i] - last_pos >= mid){
            last_pos = dist[i];
            count++;
        }
        if(count == c)
            return true;
    }
    return false;
}

int binary_search(vector<ll> dist, int n, int c){
    ll low = 0, high = dist[n-1]-dist[0];
    ll ans = -1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(check(dist, mid, n, c)){
            ans = mid;
            low = mid+1;
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
        int n, c;
        cin >> n>> c;
        vector<ll> dist(n);
    
        for(int i =0; i<n; i++){
            cin>>dist[i];
        }
        sort(dist.begin(), dist.end());
    
        cout<<binary_search(dist, n, c)<<endl;
    }
	// Write your code here
    
}