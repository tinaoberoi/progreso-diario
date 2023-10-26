#### Count no of different connected components in graph
```
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

map<int, list<int>> adjList;
map<int, bool> vis;
map<int, int> comp;

void dfsUtil(int node){
    vis[node] = true;
    cout<<node<<" ";
    for(auto n : adjList[node]){
        if(!vis[n]){
            dfsUtil(n);
        }
    }
}

void dfs(){
    int count = 0;
    for(auto list : adjList){
        if(!vis[list.first]){
            dfsUtil(list.first);
            cout<<endl;
            cout<<"Increasing count "<<list.first<<endl;
            count++;
        }
    }
    cout<<"Count is = "<<count<<endl;
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
    dfs();
    return 0;
}

```
