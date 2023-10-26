/*
https://codeforces.com/problemset/problem/71/A
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		int len = s.length();
		if(len>10){
			string ans = "";
			ans+=s[0];
			ans+=to_string(len - 2);
			ans+=s[len-1];
			cout<<ans<<endl;
		}else{
			cout<<s<<endl;
		}
	}
	return 0;
}