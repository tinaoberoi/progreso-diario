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
<<<<<<< HEAD
=======

>>>>>>> 75c1b6d25305f1e4f8f398d5f9fea9008d348507
##### AllConstruct
```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;
unordered_map<string, vector<string>> dp;
vector<vector<int>> maze;
vector<double> p;
vector<vector<string>> all;
vector<vector<string>> countConstruct(vector<string> v, string target){
    vector<vector<string>> res;
    pair<vector<string>, bool> resp;
    if(target == ""){
        vector<string> temp;
        temp.push_back(target);
        res.push_back(temp);
        return res;
    }
    
    for( auto word : v){
        int pos = target.find(word);
        if(pos == 0){
            auto remainingStr = target.substr(word.length());
            //cout<<"remaining target = "<<remainingStr<<endl;
            //ans += countConstruct(v, remainingStr);
            auto temp = countConstruct(v, remainingStr);
            cout<<"for using word="<<word<<"and remaining str"<<remainingStr<<endl;
            for(auto x : temp){
                for(auto y: x){
                    cout<<y<<" ";
                }
                cout<<endl;
            }
            int n = temp.size();
            temp[n-1].push_back(word);
            cout<<"for using word="<<word<<"and remaining str"<<remainingStr<<"after doing push operation"<<endl;
            for(auto x : temp){
                for(auto y: x){
                    cout<<y<<" ";
                }
                cout<<endl;
            }
            res.push_back(temp[0]);
        }
    }
    return res;
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
    
    auto temp = countConstruct(v, target);
    for(auto x : temp){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

```
