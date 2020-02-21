/*
Well, the annual technical symposium of Department of Computer Technology is around the corner. All that we need, to make it a grand success is Publicity among the peer groups ( ofCourse the sponsors too :P ). We decided to share the job between the student groups. As per the plan we decided to meet people in person and influence them to attend Prayatna. But to meet them we have to go to various student groups. To do so, we had to cut our classes. But being studious. students refused to cut more classes. Instead of meeting every one in person we decided to meet few people such that the person to whom we pass the news will spread it to all his friends. And those friends will pass it to other friends and so on. Your task is to find the number of people to be met by the organizers to spread the news.

Caution: Large I/O

Input
First line of input is 't' - Test cases. Follwed by N, the number of peers in the testcase ( 0 to N-1 ). followed by the number of friend description 'e'. Following are 'e' descriptions of type "a b" denoting 'a' friends with 'b'. If 'a' is friends with 'b' then 'b' is friends with 'a'.

Output
Output contains t line, the number of people, the organizers have to meet in person for each test case.

Example
Input:
2

4
2
0 1
1 2

3
0

Output:
2
3
*/

#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;

template<typename T>
class Graph{
	unordered_map<T, list<pair<T, int>>> m;
public:
	void addEdges(T u, T v, int dist, bool bidir = true){
		m[u].push_back(make_pair(v, dist));
		if(bidir){
			m[v].push_back(make_pair(u, dist));
		}
	}
	void printAdj(){
		for(auto j : m){
			cout<<j.first<<"->";
			for (auto l : j.second)
			{
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

			//cout<<p<<" ";

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
	int t;
	cin>>t;
	while(t--){
		int n, e;
		cin>>n;
		cin>>e;
		vis.assign(n, false);
		Graph <int> g;
		while(e--){
			int a, b;
			cin>>a>>b;
			g.addEdges(a, b, -1);
		}
		//g.printAdj();
		
		int count = 0;
		for(int i =0; i<n; i++){
			if(!vis[i]){
				g.bfs(i);
				count++;
			}
		}
		cout <<count<<endl;
		
	}
}