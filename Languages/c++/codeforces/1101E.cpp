#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long N = 1000000007;
vector<pair<int, int>> bills;

void check(int h, int w){
  for(int i =0; i<bills.size(); i++){
    if(min(bills[i].first, bills[i].second) > min(h, w)){
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int maxa = 0, maxb = 0;
  string sign;
  int x, y;
  while(n--){
    cin>>sign>>x>>y;
    if(x<y)
      swap(x, y);
    if(sign[0] == '+'){
      maxa = max(maxa, x);
      maxb = max(maxb, y);
    }else{
      cout<<(maxa<=x && maxb<=y ? "YES" : "NO")<<endl;
    }
  }
  return 0;
}