### Grid Traveller

Recursive

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;
vector<int> dp;
vector<vector<int>> maze;

int gridWays(int i, int j, int n, int m){
    if(i == n && j == m){
        return 1;
    }
    if(i>n || j >m || i<0 || j< 0){
        return 0;
    }
    
    return gridWays(i+1, j, n, m) + gridWays(i, j+1, n, m);
}

int main(){
    int n, m;
    cin>>m>>n;
    maze.resize(n+1, vector<int>(n+1, 0));
    
    dp.resize(n+1, 0);
    dp[1] = dp [2] = 1;
    cout<<gridWays(1, 1, m, n)<<endl;
    return 0;
}
``` 
Time Complexity: O(2^(n+m))
Space Complexity: O(n+m)

Memoization Approach

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

ll gridWays(ll i, ll j, ll n, ll m){
    if(i == n && j == m){
        return 1;
    }
    if(i>n || j >m || i<0 || j< 0){
        return 0;
    }
    if(maze[i][j] != -1)
        return maze[i][j];
    maze[i][j] = gridWays(i+1, j, n, m) + gridWays(i, j+1, n, m);
    return maze[i][j];
}

int main(){
    ll n, m;
    cin>>n>>m;
    maze.resize(n+1, vector<ll>(m+1, -1));
    maze[n][m] = 1;
    maze[0][0] = 0;
    cout<<gridWays(1, 1, n, m)<<endl;
    return 0;
}

```
Time Complexity: O(m*n)
Space Complexity: O(m+n)

Tabulation Method

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

ll gridWays(ll i, ll j, ll n, ll m){
    for(ll i = 0; i<=n; i++){
        for(ll j=0; j<=m; j++){
            auto curr = maze[i][j];
            if(j+1 <= m){
                maze[i][j+1] +=curr;
            }
            if(i+1 <= n){
                maze[i+1][j] += curr;
            }
        }
    }
    return maze[n][m];
}

int main(){
    ll n, m;
    cin>>n>>m;
    maze.resize(n+1, vector<ll>(m+1, 0));
    maze[1][1] = 1;
    cout<<gridWays(1, 1, n, m)<<endl;
    return 0;
}

```
Time Complexity: O(m*n)
Space Complexity: O(m*n)