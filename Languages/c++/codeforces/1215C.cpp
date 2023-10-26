#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--){
    string a;
    cin>>a;

    string s[2];

    for(auto x : a){
      s[int(x-'0')&1] +=x;
    }

    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());

    string res = "";

    while(!(s[0].empty() && s[1].empty())){
      if(s[0].empty()){
        res+=s[1].back();
        s[1].pop_back();
        continue;
      }
      if(s[1].empty()){
        res+=s[0].back();
        s[0].pop_back();
        continue;
      }else if(s[0].back() < s[1].back()){
        res+=s[0].back();
        s[0].pop_back();
      }else{
        res+=s[1].back();
        s[1].pop_back();
      }
    }

    cout<<res<<endl;
  }
  return 0;
}