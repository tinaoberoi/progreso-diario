### Longest Path in a graph
#### Solution 1: using DFS (can work for Bothe directed and non directed)
```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> in;
int count = 0;

void dfs(int v, int prev_len, int* max_len){
    vis[v] = true;
    int curr_len = 0;
    for(auto j : adj[v]){
        if(!vis[j]){
            curr_len = prev_len+1;
            dfs(j, curr_len, max_len);
        }
        *max_len = max(*max_len, curr_len);
        curr_len =  0;
    }
}
int dfsUtil(int n){
    int max_len = 0;
    for(int i =0; i<=n; i++){
        if(!vis[i]){
            dfs(i, 0, &max_len);
        }
    }
    return  max_len;
}

int main(){
    int n, e;
    cin>>n>>e;
    vis.assign(n+1, false);
    //in.assign(n+1, 0);
    adj.resize(n+1);
    vis[0] = true;
    for(int i =0; i<e; i++){
        int v, w;
        cin>>v>>w;
        adj[v].push_back(w);
    }
    /*
    for(int i =1; i<n+1; i++){
        cout<<i<<"->[";
        for(auto j : adj[i]){
            cout<<j<<",";
        }
        cout<<"]"<<endl;
    }*/
    cout<<topSort(n)<<endl;
    //cout<<max_dist<<endl;
    return 0;
    
}

```
Time Complexity: O(V*(V+E))
#### Solution 2: using Topological Sort (works only for DAG)

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> in;
int count = 0;

void dfs(int v, stack<int> &st){
    vis[v] = true;
    for(auto j : adj[v]){
        if(!vis[j]){
            vis[j] = true;
            dfs(j, st);
        }
    }
    st.push(v);
}
int topSort(int n){
    vector<int> dist(n+1, 0);
    stack<int> st;
    for(int i =0; i<=n; i++){
        if(!vis[i]){
            dfs(i, st);
        }
    }
    int max_dist = 0;
    while(!st.empty()){
        int v = st.top();
        st.pop();
        for(auto j : adj[v]){
            dist[j] = max(dist[j], dist[v]+1);
        }
    }
    for(int i =0; i<=n; i++){
        max_dist = max(max_dist, dist[i]);
    }
    //cout<<"maximum dist"<<max_dist<<endl;
    return max_dist;
}

int main(){
    int n, e;
    cin>>n>>e;
    vis.assign(n+1, false);
    //in.assign(n+1, 0);
    adj.resize(n+1);
    vis[0] = true;
    for(int i =0; i<e; i++){
        int v, w;
        cin>>v>>w;
        adj[v].push_back(w);
    }
    /*
    for(int i =1; i<n+1; i++){
        cout<<i<<"->[";
        for(auto j : adj[i]){
            cout<<j<<",";
        }
        cout<<"]"<<endl;
    }*/
    cout<<topSort(n)<<endl;
    //cout<<max_dist<<endl;
    return 0;
    
}
```
Time Complexity: O(V+E)

#### Solution3:DP Solution
```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> in;
vector<int> dp;
int count = 0;

void dfs(int v){
    vis[v] = true;
    for(auto j : adj[v]){
        if(!vis[j]){
            dfs(j);
        }
        dp[v] = max(dp[v], 1+dp[j]);
    }
}
int dfsUtil(int n){
    int max_len = 0;
    for(int i =0; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i=0; i<=n; i++){
        max_len = max(max_len, dp[i]);
    }
    return  max_len;
}

int main(){
    int n, e;
    cin>>n>>e;
    vis.assign(n+1, false);
    //in.assign(n+1, 0);
    adj.resize(n+1);
    dp.resize(n+1);
    vis[0] = true;
    for(int i =0; i<e; i++){
        int v, w;
        cin>>v>>w;
        adj[v].push_back(w);
    }
    /*
    for(int i =1; i<n+1; i++){
        cout<<i<<"->[";
        for(auto j : adj[i]){
            cout<<j<<",";
        }
        cout<<"]"<<endl;
    }*/
    cout<<dfsUtil(n)<<endl;
    //cout<<max_dist<<endl;
    return 0;
    
}
```
Time Complexity: O(N+M)