/* 
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/marriage-problem/description/

Time Complexity of each is O(q1+q2+q3+X+Y) 
Space Complexity O(X+Y)
*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct subset
{
	int parent, sz;
	int boys, girls;
};

vector<subset> subsets;
int x, y, n ;

void initialize(){
	for(int i =0; i<n; i++){
		subsets[i].parent = i;
		subsets[i].sz = 1;
		subsets[i].girls = 0;
		subsets[i].boys = 0;
		if(i<x){
			subsets[i].boys = 1;
		}else{
			subsets[i].girls = 1;
		}
	}
}

int find(int i){
	while(subsets[i].parent != i){
		subsets[i].parent = find(subsets[i].parent);
	}
	return subsets[i].parent;
}

void uniona(int A, int B){
	if(A == B)
		return;
	int root_A = find(A);
	int root_B = find(B);
	if(subsets[root_A].sz < subsets[root_B].sz){
		subsets[root_A].parent = root_B;
		subsets[root_B].sz+=subsets[root_A].sz;
		subsets[root_B].girls+=subsets[root_A].girls;
        subsets[root_B].boys+=subsets[root_A].boys;
	
	}else{
		subsets[root_B].parent = root_A;
		subsets[root_A].sz+=subsets[root_B].sz;
		subsets[root_A].girls+=subsets[root_A].girls;
		subsets[root_A].boys+=subsets[root_A].boys;	
	}
}

int main(){
	ll int q1, q2, q3;
	cin>>x>>y;
	n = x+y;
	subsets.clear();
	subsets.resize(n);

	cin>>q1;
	int a, b;
	while(q1--){
		cin>>a>>b;
		assert(1<=a && a<=y);
		assert(1<=b && b<=y);
		assert(a!=b);
		uniona(find(a-1), find(b-1));

	}
	cin>>q2;
	while(q2--){
		cin>>a>>b;
		assert(1<=a && a<=y);
		assert(1<=b && b<=y);
		assert(a!=b);
		uniona(find(x+a-1), find(x+b-1));
	}
	cin>>q3;
	while(q3--){
		cin>>a>>b;
		assert(1<=a && a<=y);
		assert(1<=b && b<=y);
		uniona(find(a-1), find(x+b-1));
	}
	ll int ans = 0;
	for(int i =0; i<x; i++){
		ll int tmp = (y-subsets[find(i)].girls);
		ans+=tmp;
	}
	cout<<ans<<endl;
	return 0;
}