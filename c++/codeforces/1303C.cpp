#include<bits/stdc++.h>
using namespace std;
#define ll long long
string ans = "";

void helper(string s){
  vector<bool> used(26);
  string t(1, s[0]);
  used[s[0] - 'a'] = true;
  int pos = 0;

  for(int i =1; i<s.length(); i++){
    if(used[s[i]-'a']){
      if(pos >0 && t[pos-1] == s[i]){
        pos--;
      }else if(pos+1 < t.length() && t[pos+1] == s[i]){
        pos++;
      }else{
        cout<<"NO"<<endl;
        return;
      }
    }else{
      if(pos == 0){
        t = s[i] + t;
      }else if(pos == t.length() - 1){
        t+=s[i];
        pos++;
      }else{
        cout<<"NO"<<endl;
        return;
      }
    }
    used[s[i] - 'a'] = true;
  }

  for(int i =0; i<26; i++){
    if(!used[i]){
      t+=char(i+'a');
    }
  }

  cout<<"YES"<<endl<<t<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    helper(s);
  }
  return 0;
}