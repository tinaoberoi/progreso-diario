#include<bits/stdc++.h>
using namespace std;

void print_sub(string s, string out){
	if(s.length() == 0){
		cout<<out<<endl;
		return;
	}

	print_sub(s.substr(1), out);
	print_sub(s.substr(1), out+s[0]);
}

int main(){
	string s;
	s = "abc";

	print_sub(s, "");
	return 0;
}