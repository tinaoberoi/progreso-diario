#### Shortest path in a Binary Matrix

Approach: tried solving using dfs

```
int dx[] = {-1, 1, 0, 0, 1};
int dy[] = {0, 0, -1, 1, 1};
class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>= m){
            return false;
        }
        return true;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m){
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(!isValid(i, j, n, m) || grid[i][j] == 1)
            return -1;
        vis[i][j] = true;
        int ans = -1;
        for(auto t =0; t<5; t++){
            int x = i+dx[t];
            int y = j+dy[t];
            
            if(isValid(x, y, n, m) && grid[x][y] == 0 && !vis[x][y]){
                cout<<"Valid for x ="<<x<<"and y ="<<y<<" i="<<i<<"and j ="<<j<<endl;
                auto val = dfs(grid, vis, x, y, n, m);
                cout<<"val = "<<val<<"and ans = "<<ans<<endl;
                if(val>0 && ans == -1){
                    ans = val+1;
                } else if(val > 0 && ans >0 ){
                    ans = min(val+1, ans);
                }
            }
        }
        return ans;
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        return dfs(grid, vis, 0, 0, n, m);
    }
};
```
Problem: whenever you see 'shortest' in path problem, dfs should be out of consideration. In case of dfs it will return the first possible path rather than the shortest path
If then you go through every unvisited point it will return TLE.

Approach - using bfs
```
```
