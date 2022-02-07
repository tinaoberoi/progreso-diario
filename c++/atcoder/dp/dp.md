### canConstruct

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;
unordered_map<string, bool> dp;
vector<vector<int>> maze;
vector<double> p;

bool canConstruct(vector<string> v, string target){
    if(target == "")
        return true;
    if(dp.find(target) != dp.end()){
        return dp[target];
    }
    for( auto word : v){
        int pos = target.find(word);
        if(pos == 0){
            auto remainingStr = target.substr(word.length());
            cout<<"remaining target = "<<remainingStr<<endl;
            auto res = canConstruct(v, remainingStr);
            dp[remainingStr] = res;
            if(res)
                return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    string target;
    cin>>target;
    int len = target.length();
    
    cout<<canConstruct(v, target)<<endl;
    
    return 0;
}
```

#### countContruct
```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;
unordered_map<string, int> dp;
vector<vector<int>> maze;
vector<double> p;

int countConstruct(vector<string> v, string target){
    if(target == "")
        return 1;
    if(dp.find(target) != dp.end()){
        return dp[target];
    }
    int ans = 0;
    for( auto word : v){
        int pos = target.find(word);
        if(pos == 0){
            auto remainingStr = target.substr(word.length());
            cout<<"remaining target = "<<remainingStr<<endl;
            //ans += countConstruct(v, remainingStr);
            dp[target] += countConstruct(v, remainingStr);
        }
    }
    return dp[target];
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    string target;
    cin>>target;
    int len = target.length();
    
    cout<<countConstruct(v, target)<<endl;
    
    return 0;
}

```
