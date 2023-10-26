###Recurrsive Method

```

```
### Tabulation Method

```
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> maze;
vector<bool> isPos;
vector<int> howSum(int targetSum, vector<int> vec){
    vector<int> res;
    for(int i =0; i<= targetSum; i++){
        if(isPos[i]){
            for(auto v : vec){
                int curr = i+v;
                if(!isPos[curr]){
                    isPos[curr] = true;
                    maze[curr].push_back(v);
                    for(auto m : maze[i]){
                        maze[curr].push_back(m);
                    }
                }
                if(curr == targetSum){
                    cout<<curr<<endl;
                    return maze[curr];
                }
            }
        }
    }
    return res;
}

int main(){
    int targetSum, n;
    cin>>targetSum;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    maze.resize(targetSum+1);
    isPos.resize(targetSum+1, false);
    isPos[0] = true;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> v = howSum(targetSum, arr);
    //cout<<v.size()<<endl;
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Hello"<<endl;
    return 0;
}

```
Time Com
