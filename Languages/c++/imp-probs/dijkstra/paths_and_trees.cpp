/*
https://codeforces.com/problemset/problem/545/E
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered<int, list<pair<int, int>>> graph;

void helper(ll n, ll u){
	vector<int> dist(n, -1);
	queue<pair<int, int>>q;
	q.push({u, 0});
}

int main(){
	freeopen("input.txt", "r", stdin);
	ll n, m;
	cin>>n>>m;
	graph.clear();
	for(int i =0; i<m; i++){
		cin>>a>>b>>c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	ll u;
	cin>>u;
	helper(n,u);
	return 0;
}