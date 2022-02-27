### Topological Sort
Logic: for every directed edge uv, vertex u comes before v in the ordering.
- Not possible if graph not DAG
- The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no in-coming edges)
- Not every graph can have a topological sort, 
Resources:
https://www.youtube.com/watch?v=eL-KzMXSXXI
https://cp-algorithms.com/graph/topological-sort.html
##### Topological Ordering:
DFS is modified to create topological sorting algorithm
Difference between DFS and Topological
- In DFS we first print the number and then go for its adjacent vertexes
- In TS we maintain a stack rather than printing the number, we recursively call TS on adjacent vertices, then push it to the stack. Note that its pushed into the stack only when all its adjacent vertices are already in the stack.

```
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
stack<int> st;

void dfs(int v){
    vis[v] = true;
    for(auto i : adj[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
    st.push(v);
}

void topSort(){
    int n = adj.size();
    for(int i =0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    vis.assign(n, false);
    adj.resize(n);
    for(int i=0; i<e; i++){
        int v, w;
        cin>>v>>w;
        adj[v].push_back(w);
    }
    for(int i =0; i<n; i++){
        cout<<i<<" -> [";
        auto temp = adj[i];
        for(int j =0; j<temp.size(); j++){
            cout<<temp[j]<<",";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
    topSort();
}
```

Time Complexity = O(V+E)
Space Complexity = O(V)

Applications: 
- Course Prerequisites: You have to complete course intro to c++ to do advance also in c++
- Real World: used for scheduling jobs from given dependency from other jobs
In CS eg: scheduling, ordering of formula during cell evaluation in spreadsheets

Common Problems:
A common problem in which topological sorting occurs is the following. There are n variables with unknown values. For some variables we know that one of them is less than the other. You have to check whether these constraints are contradictory, and if not, output the variables in ascending order (if several answers are possible, output any of them). It is easy to notice that this is exactly the problem of finding topological order of a graph with n vertices.

########## How to detect cycles using topSort?
```
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
stack<int> st;
 
void dfs(int v){
    vis[v] = true;
    sort(adj[v].begin(), adj[v].end());
    for(auto i : adj[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
    st.push(v);
}
 
void topSort(){
    int n = adj.size();
    for(int i =1; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    int index = 0;
    unordered_map<int, int> pos;
    vector<int> tsort;
    while(!st.empty()){
        //cout<<st.top()<<" ";
        //st.pop();
        pos[st.top()] = index;
        tsort.push_back(st.top());
        index++;
        st.pop();
    }
    bool ans = false;
    for(int i =1; i<n; i++){
        for(auto j : adj[i]){
            if(pos[i] > pos[j]){
                ans = true;
            }
        }
    }
    if(ans){
        cout<<"Sandro fails"<<endl;
    } else {
        for(int i=0; i<tsort.size(); i++){
            cout<<tsort[i]<<" ";
        }
    }
}
 
int main(){
    int n, e;
    cin>>n>>e;
    vis.assign(n+1, false);
    adj.resize(n+1);
    for(int i=0; i<e; i++){
        int v, w;
        cin>>v>>w;
        adj[v].push_back(w);
    }
    topSort();
    return 0;
}
```