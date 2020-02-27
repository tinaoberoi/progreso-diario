#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long N = 1000000007;

int main(){
  ios::sync_with_stdio(false);
  int n, m;
  cin>>n>>m;
  vector<set<char>> letterSet(m);
  for(int i =0; i<n; i++){
    string x;
    cin>>x;
    for(int j =0; j<m; j++){
      letterSet[j].insert(x[j]);
    }
  }

  ll ans = 1;
  for(int i=0; i<m; i++){
    ans*=letterSet[i].size();
    ans%=N;
  }
  cout<<ans<<endl;

  return 0;
}