/*
https://codeforces.com/problemset/problem/118/A
*/

#include<bits/stdc++.h>
using namespace std;

string vowels = "aeiouy";

bool not_vowel(char c){
	for(int j = 0; j<6; j++){
		if(c == vowels[j])
			return false;
	}
	return true;
}

int main(){
	string s;
	cin>>s;
	string ans = "";
	int i =0;
	int len = s.length();
	while(i<len){
		//cout<<s[i]<<"s[i]"<<endl;
		if(not_vowel(tolower(s[i]))){
			ans+=".";
			ans+=tolower(s[i]);
			//cout<<ans<<"=ans"<<endl;
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}