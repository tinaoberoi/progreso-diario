####### Kahn's Topological Sorting Algorithm
Observations:
- The first vertex in topological sorting has in-degree 0 (as no incoming vertex)
- A DAG has atleast one vertex as in degree 0 and atleast one vertex with out degree 0
Proof:
We know in DAG all paths are of finite length. Let S be the longest path from u (src) to v (dest).
Since S is the longest path, and no cycles exist there can be no incoming paths to u and no outgoing paths from v.
Thus, indegree(u) = 0 and outdegree(v) = 0
- Algorithm:
   - Have an in degree vector with every node in degree as 0 at first.
   - traverse through every node and increment the child nodes in degree vector by 1
   - traverse again through in degree node and check if any node has in degree 0 put these in queue
   - loop through the queue for every element child's see if the in degree - 1 is 0, if yes put it        into queue (cause now it will act as parent)

```
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> adj;
vector<bool> vis;

void topSort(int n){
    cout<<"starting topSort"<<endl;
    vector<int> in(n, 0);
    for(int i =0; i<n; i++){
        for(auto j : adj[i]){
            in[j]++;
        }
    }
    queue<int> q;
    vector<int> topSortArr;
    for(int i =0; i<n; i++){
        if(in[i] == 0){
            q.push(i);
            cout<<"pushed i in queue"<<i<<endl;
        }
            
    }
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<"Dealing with "<<u<<endl;
        vis[u]= true;
        topSortArr.push_back(u);
        vector<int>:: iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); it++){
            in[*it]--;
            if(in[*it] == 0){
                q.push(*it);
                cout<<"pushed i in queue "<<*it<<endl;
            }
                
             
        }
        cnt++;
    }
    cout<<"count="<<cnt<<endl;
    if(cnt != n){
        cout<<"cycle exists"<<endl;
    } else {
        for(int i =0; i<n; i++){
            cout<<topSortArr[i]<<" ";
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    vis.assign(n, false);
    adj.resize(n);
    for(int i =0; i<e; i++){
        int v, w;
        cin>>v>>w;
        adj[v].push_back(w);
    }
    for(int i =0; i<n; i++){
        
    }
    topSort(n);
}
```
Time Complexity : O(V+E);
Space Complexity: O(V) due to the queue, vis, in degree list