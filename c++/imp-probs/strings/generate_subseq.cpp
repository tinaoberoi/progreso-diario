#include<bits/stdc++.h>
using namespace std;
vector<string> v(1000, "");

int subs (string s){
	if(s.empty()){
		v[0] = "";
		return 1;
	}
	string smallstring = s.substr(1);
	int smallOutSize = subs(smallstring);
	for(int i =0; i<smallOutSize; i++){
		v[i+smallOutSize] = s[0] + v[i];
	}
	return 2*smallOutSize;
}

int main(){
	string s;
	getline(cin, s);
	cout<<s;
	
	int count = subs(s);
	
	for(int i =0; i<count; i++){
		cout<<v[i]<<endl;
	}
	return 0;
}