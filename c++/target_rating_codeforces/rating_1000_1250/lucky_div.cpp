/*
http://codeforces.com/problemset/problem/122/A
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	bool ans = 0;
	if(n%4 == 0 || n%7 == 0)
		ans = 1;
	else{
		while(n){
			int digit = n%10;
			if(digit%4 == 0 || digit%7 == 0){
				ans = 1;
			}else{
				ans = 0;
				break;
			}
			n = n/10;
		}
	}
	cout<<ans<<endl;
	return 0;
}