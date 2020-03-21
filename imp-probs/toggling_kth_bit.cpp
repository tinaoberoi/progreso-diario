/*
For a given number n, if k-th bit is 0, then toggle it to 1 and if it is 1 then, toggle it to 0.

Examples :

Input : n = 5, k = 1
Output : 4
5 is represented as 101 in binary
and has its first bit 1, so toggling 
it will result in 100 i.e. 4.

Input : n = 2, k = 3
Output : 6

Input : n = 75, k = 4
Output : 67
*/

#include<bits/stdc++.h>
using namespace std;

int toggle(int n, int k){
	int temp = 1 << (k-1);
	cout<<temp<<endl;
	return (n ^ (temp));
}

int main(){
	int n, k;
	cin>>n>>k;
	cout<<toggle(n, k)<<endl;
	return 0;
}