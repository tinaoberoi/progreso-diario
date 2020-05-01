#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
template<typename T>

class Graph{
	unordered_map<T, list<pair<T, int>>> m;
public:
	void addEdge(T u, T v, int dist, bool bidir = true){
		m[u].push_back(make_pair(v, dist));
		if(bidir){
			m[v].push_back(make_pair(u, dist));
		}
	}

	void printAdj(){
		for(auto j : m){
			cout<<j.first<<"->";
			for(auto l : j.second){
				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl;
		}
	}

	void dfs(int src){
		vis[src] = true;
		cout<<src<<" ";
		for(auto it = m[src].begin(); it != m[src].end(); it++){
			if(!vis[(*it).first]){
				dfs((*it).first);
			}
		}
	}
}; 
int main(){
	Graph <int> g;
	int v;
	cin>>v;
	g.addEdge(0, 1, 0); 
    g.addEdge(0, 2, 0); 
    g.addEdge(1, 2, 0); 
    g.addEdge(2, 0, 0); 
    g.addEdge(2, 3, 0); 
    g.addEdge(3, 3, 0);

    vis.assign(v, false);
    
    for(int i =0; i<4; i++){
    	if(!vis[i]){
    		g.dfs(i);	
    	}
    }

    //g.dfs(2);

	return 0;
}