/*
https://leetcode.com/problems/minimum-height-trees/
*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	int V; // no of nodes/vertices
	vector<int> degree;
	map<int, list<int>> m;
	Graph(int V){
		this->V = V;
		degree.clear();
		degree.resize(V, 0);
	}

	void addEdge(int u, int v, bool bidir = true){
		m[u].push_back(v);
		degree[u]++;
		if(bidir){
			m[v].push_back(u);
			degree[v]++;
		}
	}
	vector<int> findMHT();
};

vector<int> Graph::findMHT(){
	queue<int> q;
	for(int i =0; i<V; i++){
		if(degree[i] == 1)
			q.push(i);
	}

	while(V>2){
		int s = q.size();
		for(int i =0; i<s; i++){
			auto p = q.front();
			q.pop();
			V--;

			for(auto it = m[p].begin(); it != m[p].end(); it++){
				degree[*it]--;
				if(degree[*it] == 1){
					q.push(*it);
				}
			}
		}
	}

	std::vector<int> res;
	while(!q.empty()){
		res.push_back(q.front());
		q.pop();
	}
	return res;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    Graph G(n);
    for(auto& edge: edges){
    	G.addEdge(edge[0], edge[1]);
    }
    std::vector<int> res = G.findMHT();
    return res;
}

int main(){
	vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
	vector<int> v = findMinHeightTrees(6, edges);
	for(auto x : v){
		cout<<x<<" ";
	}
	cout<<endl;
}