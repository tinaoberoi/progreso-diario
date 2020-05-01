/* 
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/

Time Complexity of each is 
Space Complexity O(N)
*/
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
int n , m;
vector<int> Arr;
vector<int> size;
void initialize(){
	for(int i =1; i<=n; i++){
		Arr[i] = i;
		size[i] = 1;
	}
}

int root(int i){
	while(Arr[i] != i){
		i = Arr[i];
	}
	return i;
}

void weighted_union(int A, int B){
	int root_A = root(A);
	int root_B = root(B);

	if(size[root_A] > size[root_B]){
		Arr[root_B] = root_A;
		size[root_A] += size[root_B];
	}else if(root_A == root_B){
		return;
    }else {
		Arr[root_A] = root_B;
		size[root_B]+=size[root_A];
	}
}

// Driver program 
int main() 
{ 
    cin>>n>>m;
    Arr.resize(n+1, 0);
    size.resize(n+1, 1);
    initialize();
    while(m--){
    	int u, v;
    	cin>>u>>v;
    	weighted_union(u, v);
    }
    unordered_map<int, int> map;
    for(int i =1; i<=n; i++){
    	map[i]=0;
    }
    for(int i =1; i<=n; i++){
    	map[root(i)]++;
    }
    int res=1;
    for(auto it = map.begin(); it != map.end(); it++){
    	if(it->second != 0){
    		res=res*it->second;
    	}
    }
    cout<<res<<endl;
    return 0; 
}