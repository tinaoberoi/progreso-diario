### simple dfs

```
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<bool> vis;

void dfs(int node){
    vis[node] = true;
    for(auto n : adjList[node]){
        if(!vis[n]){
            dfs(n);
        }
    }
    cout<<node<<" ";
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    adjList.resize(nodes+1);
    vis.resize(nodes+1, false);
    for(int i =0; i<edges; i++){
        int v, w;
        cin>>v>>w;
        adjList[v].push_back(w);
    }
    for(int i =1; i<=nodes; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    return 0;
}
```