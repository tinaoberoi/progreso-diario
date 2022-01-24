#### Display all possible topological sorts
```
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> in;
void topSort(vector<int> &res, int n){
    bool flag = false;
    for(int i =0; i<n; i++){
        cout<<"calling for i"<<i<<endl;
        if(in[i] == 0 && !vis[i]){
            for(auto j : adj[i]){
                in[j]--;
            }
            cout<<"decreased degree connected to i "<<i<<endl;
            res.push_back(i);
            vis[i] = true;
            cout<<"Calling topSort again "<<i<<endl;
            topSort(res, n);
            
            cout<<"now erasing for i "<<i<<endl;
            vis[i] = false;
            res.erase(res.end()-1);
            cout<<"now erasing for i "<<i<<" "<<(*res.end())<<endl;
            for(auto j : adj[i]){
                in[j]++;
            }
            cout<<"setting flag true"<<endl;
            flag = true;
        }
    }
    if(!flag){
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
void allTopSort(int n){
    vector<int> res;
    cout<<"calling topsort"<<endl;
    topSort(res, n);
}
int main(){
    int n, e;
    cin>>n>>e;
    vis.assign(n, false);
    in.assign(n, 0);
    adj.resize(n);
    for(int i =0; i<e; i++){
        int v, w;
        cin>>v>>w;
        adj[v].push_back(w);
        in[w]++;
    }
    
    for(int i =0; i<n; i++){
        cout<<i<<"->[";
        for(auto j : adj[i]){
            cout<<j<<",";
        }
        cout<<"]"<<endl;
    }
    allTopSort(n);
}
```