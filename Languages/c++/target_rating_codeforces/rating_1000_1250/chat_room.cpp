/*
http://codeforces.com/problemset/problem/58/A
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1;
	cin>>s1;
	int len1 = s1.length();
	string s2 = "hello";
	int len2 = s2.length();
	int j = 0;
	for(int i =0; i<len1; i++){
	    if(s1[i] == s2[j]){
	    	j++;
	    }	
	}
	if(j == len2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}