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

In case there are blockers like the atcoder problem H Grid1

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
vector<vector<int>> dp;
vector<vector<int>> maze;
const unsigned int M = 1000000007;
int numberOfPaths(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == 1 && j == 1)
        return 1;
    if(i ==0 || j == 0)
        return 0;
    if(maze[i][j] == 0)
        return  0;
    dp[i][j] = (numberOfPaths(i-1, j) + numberOfPaths(i, j-1))%M;
    return dp[i][j];
}

int main(){
    int n, m;
    cin>>n>>m;
    
    dp.resize(n+1, vector<int>(m+1, -1));
    maze.resize(n+1, vector<int>(m+1));
    for(int i =1; i<=n; i++){
        for(int j =1; j<=m; j++){
            char input;
            cin>>input;
            if(input == '.'){
                maze[i][j] = 1;
            } else if(input == '#'){
                maze[i][j] = 0;
            }
        }
    }
    /*
    for(int i =1; i<=n; i++){
        for(int j =1; j<=m; j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //cout<<"Number of Paths "<<endl;
    cout<<numberOfPaths(n, m)<<endl;
}
```
