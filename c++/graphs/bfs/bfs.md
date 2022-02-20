### BFS

```
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

map<int, list<int>> adjList;
map<int, bool> vis;
map<int, int> comp;

void bfs (int node){
    queue<int> q;
    vis[node] = true;
    q.push(node);
    
    while(!q.empty()){
        auto t = q.front();
        cout<<t<<" ";
        q.pop();
        
        for(auto j : adjList[t]){
            if(!vis[j]){
                vis[j] = true;
                q.push(j);
            }
        }
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i =0; i<edges; i++){
        int u, w;
        cin>>u>>w;
        adjList[u].push_back(w);
    }
    for(auto list : adjList){
        cout<<list.first<<"->(";
        for(auto x : list.second){
            cout<<x<<" ";
        }
        cout<<")"<<endl;
    }
    bfs(2);
    return 0;
}

```

Time Complexity: O(V+E)
Space Complexity: O(V)