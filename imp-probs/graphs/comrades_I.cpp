/*
The Humans are at war against a very powerful alien race that invaded our solar system. The human army has n soldiers. The soldiers are numbers from 1 to n. The army has a superiority hierarchy. Every soldier has one immediate superior. The superior of a superior of a soldier is also a superior to that soldier. So, a soldier may have one or more superiors but only one immediate superior.

When a soldier has to pass a message to his superior, he cannot do so directly. If a soldier ‘x’ has to pass a message to his superior ‘y’, ‘x’ has to first pass the message to his immediate superior who will review the message. After reviewing, the immediate superior of ‘x’ will pass on the message to ‘y’ following the same procedure described above.

Given the two soldiers, ’x’ and ‘y’, your job is to determine how many reviews will take place until the message reaches ‘y’.

NOTE: Among all soldiers there is one soldier who does not have any superior. He is the commander of the whole army.

Input:

The first line of the input contains t, the number of test cases.
The first line of each test case contains n, the number of soldiers. The next line contains n space separated integers. The ith integer represents the immediate superior of the ith soldier.

The immediate superior of the commander of the army will be '0'.

The third line of each test case contains an integer q, the number of queries.
Each of the next q lines contain the two integers, x and y (x!=y).

Output:

For each query output a single integer on a line that is the number of reviews that’ll take place before the message reaches from ‘x’ to ‘y’.
In case ‘y’ is not the superior of ‘x’, print -1.

Constraints:
1<=t<=10
2<=n<=100000
1<=q<=100000
1<=x,y<=n

It is guaranteed that the commander of the army is a superior of all soldiers.

WARNING: Large Input data. Be careful with certain languages.
( For C++ users, use 'scanf' instead of 'cin')

SAMPLE INPUT 
1
5
0 1 1 2 4
4
5 1
4 2
2 3
1 3
SAMPLE OUTPUT 
2
0
-1
-1
Explanation
Soldier 5 will pass on the message to soldier 4, who will pass the message to soldier 2, and then soldier 1 will receive the message. 2 reviews took place.

Soldier 4 can directly pass the message to soldier 2. So, no reviews.

Soldier 3 is not the superior of Soldier 2, so, the answer is -1.

Soldier 3 is not the superior of Soldier 1, so, the answer is -1.

https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/comrades-i-3/description/
*/

#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;

#define ll long long
#define s(n) scanf("%d", &n)
#define sl(n) scanf("&lld", &n) 

template<typename T>
class Graph{
	map<T, list<pair<T, int>>> m;
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
	int bfs_check(T n1, T n2){
		if(n1 == n2)
			return 0;
		queue<T> q;
		q.push(n1);
		vis[n1] = true;
		int count = -1;
		int flag = 0;
		while(!q.empty()){
			auto p = q.front();
			q.pop();
			//cout<<p<<" ";

			if(p == n2){
				//cout<<"count befoe break"<<count<<endl;
				flag = 1;
				break;
			}
			for(auto it = m[p].begin(); it != m[p].end(); it++){
				if(!vis[(*it).first]){
					q.push((*it).first);
					vis[(*it).first] = true;
					count++;
					//cout<<"pushed"<<(*it).first<<" ";
					//cout<<count<<endl;
				}
			}
		}
		if(flag){
			return count;
		}
		return -1;
	}

	int dfs_check(T n1, T n2, int &count){
		if(n1 == n2)
			return 0;
		vis[n1] = true;
		int flag = 0;
		for(auto it = m[n1].begin(); it != m[n1].end(); it ++){
			if(!vis[(*it).first]){
				if((*it).first == n2){
					count++;
					flag=1;
					break;
				}
				count++;
				dfs_check((*it).first, n2, count);
			}
		}
		if(flag){
			return count;
		}
		return -1;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n, q;
	    s(n);
	    Graph<int> g;
	    //vis.assign(n, false);
	    for(int i =1; i<=n; i++){
	    	int parent;
	    	s(parent);
	    	g.addEdges(i, parent, -1, false);
	    }
	    //g.printAdj();
	    s(q);
	    while(q--){
	    	vis.assign(n, false);
	    	int n1, n2;
	    	s(n1);
	    	s(n2);
	    	int count = -1;
	    	cout<<g.dfs_check(n1, n2, count)<<endl;
	    }
	}
}