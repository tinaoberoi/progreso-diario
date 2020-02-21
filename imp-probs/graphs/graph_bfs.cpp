#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;

template<typename T>
class Graph{
	map<T, list<pair<T, int>>> m;

public:
	void addEdge(T u, T v, int dist, bool bidir = true){
		m[u].push_back(make_pair(v, dist));
		if(bidir){
			m[v].push_back(make_pair(u, dist));
		}
	}

	void printAdj(){
		for(auto j : m){
			cout<<j.first<<" -> ";
			for(auto l : j.second){
				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl;
		}
	}

	void bfs(T src){
		queue<T> q;
		q.push(src);
		vis[src] = true;
		while(!q.empty()){
			auto p = q.front();
			q.pop();

			cout<<p<<" ";

			for(auto it = m[p].begin(); it != m[p].end(); it++){
				if(!vis[(*it).first]){
					q.push((*it).first);
					vis[(*it).first] = true;
				}
			}
		}
	}
};

int main(){
	int v, e;
	cin>>v>>e;
	Graph <int> g;
	while(e--){
		int n1, n2;
		cin>>n1>>n2;
		g.addEdge(n1, n2, 0);
	}

	//g.printAdj();
	vis.assign(v, false);
	for(int i =0; i<v; i++){
		if(!vis[i]){
			g.bfs(i);
		}
	}
}