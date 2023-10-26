#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int side1, int side2, int side3){
	if(side1+side2 > side3 && side2+side3 > side1 && side1 + side3 > side2){
		return true;
	}
	return false;
}

vector<int> helper(int a, int b, int c, int d){
	vector<int> res;
	int k = c;

    while(k<=d){
	    for(int i =a; i<=b; i++){
		    for(int j =b; j<=c; j++){
				cout<<"i = "<<i<<" j= "<<j<<" k= "<<k<<endl;
				if(check(i, j, k)){
					res.push_back(i);
				    res.push_back(j);
				    res.push_back(k);

				    return res;	
			    }
		    }
	    }
	    k++;
    }
	return res;
}


int main(){
	int t;
	ll a, b, c, d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		vector<int> arr = helper(a, b, c, d);
		for(int i =0; i<arr.size(); i++){
			cout<<arr[i]<<" ";
		}
	}
	return 0;
}