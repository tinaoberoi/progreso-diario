/*https://codeforces.com/problemset/problem/112/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1, s2;
	cin>>s1>>s2;
	int len1 = s1.length();
	int len2 = s2.length();
	int ans = 0;
	for(int i =0; i<len1; i++){
		if(tolower(s1[i]) > tolower(s2[i])){
			ans = 1;
			break;
		}
		if(tolower(s1[i]) < tolower(s2[i])){
			ans = -1;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}