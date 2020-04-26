# Graph Algorithm : Dijiktras
Given a graph and a source vertex, find shortest paths from source to all vertices in the given graph
*Single source to all nodes shortest path*
* Thus known as **SSSP** (Single source shortest path algo)
* This is for weighted graphs, we can use BFS for unweighted graphs for shortest path

## How the Algorithm works?
[Explaination](https://www.youtube.com/watch?v=NR4fpjuxnPA)
Algo says

* Make the dist of source node as 0
* Initially all the nodes are not visited and its dist is inifinty.
* Pick the node with min dist (i.e. source node) --> for this we can either use Linear search (O(n)) or a Priority Queue or Set (In set you can find the node in O(1) and remove it in LogN time). Thus we will use Set. (Cannot use Priorty Queue, cause there is no opton to update, In set u can remove and insert)

# Code
*Using templates to implement algo as I want it to work for all data types*

```c++
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

unordered_map<T, list<pair<T, int>>> m; 
// map<T, list<pair<T, int>>> m (for sorted)

public:
	void addEdge(T u, T v, int dist, bool bidir = true){
		m[u].push_back(make_pair(v, dist));

		if(bidir){
			m[v].push_back(make_pair(u, dist));
		}
	}

	void printAdj(){
		//Iterate over all the key value pairs in the map
		for(auto j: m){
			cout<<j.first<<"->";

			// Iterate over the list of cities
			for(auto l: j.second){
				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl;
		}
	}

	void dijsktras(T src){
		// For every node I need a distance map
		unordered_map<T, int>dist;

		//set all distances to infinity
		for(auto j:m){
			dist[j.first] = INT_MAX; 
		}

		//Make a set to find out node of min distance
		//First parameter is dist, cause in set sorting is based on first parameter
		set<pair<int, T>> s;

		dist[src] = 0;
		s.insert(make_pair(0, src));

		while(!s.empty()){

			//Find the pair at front
			//s.begin() is pointer and *(s.begin()) will give you the pair 
			auto p = *(s.begin());

			T node = p.second;
			int nodeDist = p.first;

			s.erase(s.begin());

			//Iterate over neighbours or children of current node
			for(auto childPair:m[node]){
				if(nodeDist + childPair.second < dist[childPair.first]){
					// In set updation of particular is not possible
					// we have to remove old pair and insert new pair of updation
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if(f != s.end()){
						s.erase(f);
					}
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest], dest));

				}
			}
		}

		for(auto d : dist){
			cout<<d.first<<" is located at distance of "<<d.second<<endl;
		}
	}
};

int main(){
	/*
	Graph<int> g;
	g.addEdge(1, 2, 1);
	*/

	Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    india.printAdj();
    //india.dijsktraSSSP("Amritsar");
}

```