##### Print all paths to reach from top to bottom
Can go top/bottom or right/left

- Simple solution to print number of paths

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

int numberOfPaths(int n, int m){
    if(n == 1|| m == 1)
        return 1;
    return numberOfPaths(n-1, m) + numberOfPaths(n, m-1);
}

int main(){
    int n, m;
    cin>>n>>m;
    cout<<numberOfPaths(n, m)<<endl;
    return 0;
    
}


```
Time Complexity: Exponential

Dynamic Programming solution
```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
vector<vector<int>> adj;
vector<vector<bool>> vis;
vector<int> in;
vector<vector<int>> dp;

int numberOfPaths(int i, int j){
    if(i== 1 || j ==1)
        return dp[i][j] = 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = numberOfPaths(i-1, j) + numberOfPaths(i, j-1);
    return dp[i][j];
}

int main(){
    int n, m;
    cin>>n>>m;
    dp.resize(n+1, vector<int>(m+1, -1));
    cout<<numberOfPaths(n, m)<<endl;
}

```
Time Complexity: O(mn)
Space Complexity O(mn)

