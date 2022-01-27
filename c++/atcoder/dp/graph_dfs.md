#### DFS for graph
DFS of graph is similar to DFS of a tree. Except in graphs we may have cycles.

```
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include<cstring>
#include<map>
#include <list>
using namespace std;
using li = long long;
//int N = 1e9;
//vector<int> arr(N, 0);
string s ="";

class Graph{
public:
    map<int, bool> vis;
    map<int, list<int>> adj;
    
    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int v){
    vis[v] = true;
    cout<<v<<" ";
    
    list<int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); i++){
        if(!vis[*i]){
            DFS(*i);
        }
    }
}

int main(int argc, const char * argv[]) {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    
    g.DFS(2);
    return 0;
}
```

Time Complexity: O(V+E)
Space Complexity(V);
The above code misses the corner case: when all vertices are not connected. Non connected graphs

```
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include<cstring>
#include<map>
#include <list>
using namespace std;
using li = long long;
//int N = 1e9;
//vector<int> arr(N, 0);
string s ="";

class Graph{
    void DFSUtil(int v);
public:
    map<int, bool> vis;
    map<int, list<int>> adj;
    
    void addEdge(int v, int w);
    void DFS();
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v){
    vis[v] = true;
    cout<<v<<" ";
    
    list<int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); i++){
        if(!vis[*i]){
            DFSUtil(*i);
        }
    }
}

void Graph::DFS(){
    for(auto i: adj){
        if(!vis[i.first]){
            DFSUtil(i.first);
        }
    }
}

int main(int argc, const char * argv[]) {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    
    g.DFS();
    return 0;
}

```
Time Complexity: O(V+E)
Space Complexity(V);