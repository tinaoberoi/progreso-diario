### Can Sum

Recursive Solution

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>
# define ll long long

using namespace std;
vector<ll> dp;
vector<vector<ll>> maze;

bool canSum(ll targetSum, vector<ll> arr){
    if(targetSum == 0)
        return true;
    if(targetSum < 0)
        return false;
    if(arr.size() == 0)
        return false;
    for(auto v : arr){
        if(canSum(targetSum - v, arr))
            return true;
    }
    return false;
}

int main(){
    ll targetSum;
    cin>>targetSum;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<canSum(targetSum, arr)<<endl;
    return 0;
}

```
M = targetSum
N = array len
Time Complexity: O(N^M)
Space Complexity: O(M)

Memoization
```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>
# define ll long long

using namespace std;
vector<ll> dp;
vector<bool> maze;

bool canSum(ll targetSum, vector<ll> arr){
    if(targetSum == 0)
        return true;
    if(targetSum < 0)
        return false;
    if(arr.size() == 0)
        return false;
    if(maze[targetSum])
        return true;
    for(auto v : arr){
        auto newSum = targetSum - v;
        if(newSum >= 0){
            maze[newSum] = canSum(newSum, arr);
            if(maze[newSum])
                return true;
        }
    }
    return false;
}

int main(){
    ll targetSum;
    cin>>targetSum;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i =0; i<n; i++){
        cin>>arr[i];
    }
    maze.resize(targetSum+1, false);
    maze[0] = true;
    cout<<canSum(targetSum, arr)<<endl;
    return 0;
}

```
Time Complexity: O(targetSum*arr.len)
Space Complexity: O(targetSum)

Tabular Code

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>
# define ll long long

using namespace std;
vector<ll> dp;
vector<vector<ll>> maze;

bool canSum(ll targetSum, vector<ll> arr){
    if(targetSum == 0)
        return true;
    if(arr.size() == 0)
        return false;
    vector<bool> dp(targetSum+1, false);
    dp[0] = true;
    for(ll i =0; i<=targetSum; i++){
        ll curr = i;
        if(dp[curr]){ // its possible to create curr value
            for(ll j =0; j<arr.size(); j++){
                ll index = curr+arr[j];
                if(index <= targetSum){
                    dp[index] = true;
                }
            }
        }
    }
    if(dp[targetSum])
        return true;
    return false;
}

int main(){
    ll targetSum;
    cin>>targetSum;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<canSum(targetSum, arr)<<endl;
    return 0;
}
```
Time Complexity: O(targetSum*arr.len)
Space Complexity: O(targetSum)