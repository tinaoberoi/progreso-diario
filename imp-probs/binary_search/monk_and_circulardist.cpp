#include<bits/stdc++.h> 
using namespace std;
#define ll long long

ll binary_search(ll r, std::vector<ll> dist){
	ll n = dist.size();
	ll sq_r = pow(r, 2);
	ll low = 0, high = n-1;
	while(low<=high){
		ll mid = low+(high-low)/2;
		if(dist[mid]<=sq_r){
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return low;
}
// Driver program 
int main() 
{ 
    ll n, q;
    cin>>n;
    vector<vector<ll>> vec(n, vector<ll>(2));
    for(ll i =0; i<n; i++){
    	cin>>vec[i][0]>>vec[i][1];
    }
    vector<ll> dist(n, 0);
    for(ll i =0; i<n; i++){
    	dist[i] = pow(vec[i][0], 2) + pow(vec[i][1], 2);
    }
    sort(dist.begin(), dist.end());

    ll r;
    cin>>q;
    while(q--){
       cin>>r;
       cout<<binary_search(r, dist)<<endl;
    }
    

    

    return 0; 
} 