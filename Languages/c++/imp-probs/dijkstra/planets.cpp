/*
https://codeforces.com/problemset/problem/229/B
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_set<int> waits[100001];
unordered_map<ll, list<pair<ll, ll>>> graph;

ll helper(ll n){
	vector<ll> dist(n+1, -1);
	queue<pair<int,int>> q;
	q.push({1, 0});

	while(!q.empty()){
		ll len = q.size();
		for(ll i =0; i<len; i++){
			auto p = q.front();
		    q.pop();

		    ll node = p.first;
		    ll nodeDist = p.second;
		    //if(dist[node]<nodeDist)continue;
		    
		    while(waits[node].count(nodeDist)) nodeDist++;
		    for(auto childPair : graph[node]){
		    	auto temp_time = nodeDist + childPair.second;
			    if( temp_time < dist[childPair.first] || dist[childPair.first] == -1){
			    	dist[childPair.first] = nodeDist + childPair.second;
				    q.push({childPair.first, (dist[childPair.first])});
				}
			}
		}
	}
	/*for(int i =0; i<n+1; i++){
		cout<<i<<" "<<dist[i]<<endl;
	}*/
	return dist[n];
}
	

int main(){
	ll n,m;
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	ll a,b,c;
	graph.clear();
	while(m--){
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	/*for(auto j : graph){
		cout<<j.first<<"->";
		for(auto i : j.second){
			cout<<"("<<i.first<<","<<i.second<<")";
		}
		cout<<endl;
	}*/
    for(ll i=1; i<n+1; i++){
		ll k, x;
		cin>>k;
		while(k--){
			cin>>x;
			waits[i].insert(x);
		}
	}
	/*for(int i =1; i<n+1; i++){
		cout<<"Node "<<i<<"->";
		for(auto itr = waits[i].begin(); itr!=waits[i].end(); itr++){
			cout<<*itr<<",";
		}
		cout<<endl;
	}*/
	cout<<helper(n)<<endl;

	return 0;
}