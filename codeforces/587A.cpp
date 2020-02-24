/*
https://codeforces.com/problemset/problem/587/A
*/

/*
Takeaways: 
-> How to calculate signed bits
-> TLE without ios:sync_with_stdio(false)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1000100;
vector<int> a(MAX, 0);

int main(){
  ios::sync_with_stdio(false);
  ll n;
  cin>>n;
  while(n--){
    int x;
    cin>>x;
    a[x]++;
  }
  ll ans = 0;
  for(int i =0; i<MAX-1; i++){
    a[i+1]+=a[i]/2;
    a[i]%=2;
    ans+=a[i];
  }
  cout<<ans<<endl;
  return 0;
}