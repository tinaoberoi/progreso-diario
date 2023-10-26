#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int t;
	cin>>t;
	ll x, y, a, b;
	ll ans = 0; 
	while(t--){
		cin>>x>>y;
		cin>>a>>b;
		if(x == 0 && y == 0){
			cout<<0<<endl;
			break;
		}
		if(x == y){
			cout<<min(abs(x*a), abs(x*b))<<endl;
			break;
		}
		ll op1 = (abs(abs(x)-abs(y)))*a + abs(min(x, y))*b;
		//cout<<abs(abs(x)-abs(y))*a << " "<<abs(min(x, y))*b<<" "<<endl; 
		ll op2 = max(x, y)*a + min(x, y)*a;

		cout<<min(op2, op1)<<endl;
	}
	return 0;
}
