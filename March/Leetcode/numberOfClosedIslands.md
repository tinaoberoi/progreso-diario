##### Number of closed Islands
Here 0 is land and 1 is water
Closed islands is the ones that are surrounded by water.(right, left, top, bottom)
So the 0's on the corners are not counted as closed islands since they are not surreounded by water from all sides.
Approach: 
- Traverse through all corners with value = 0(i.e land), and their connected nodes and mark visited
- Now tranverse through the remaining land nodes and keep a count. Every disconnected graph will increase the count.

```
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m){
        cout<<"DFS for i ="<<i<<"and j ="<<j<<endl;
        vis[i][j] = true;
        for(int t =0; t<4; t++){
            int x = i+dx[t];
            int y = j+dy[t];
            cout<<"Checking for x = "<<x<<"y= "<<y<<endl;
            if(isValid(x, y, n, m) && !vis[x][y] && grid[x][y] == 0 ){
                cout<<"Callling dfs value for x = "<<x<<"y="<<y<<endl;
                dfs(grid, vis, x, y, n, m);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if((i*j == 0 || i == n-1 || j == m-1) && !vis[i][j] && grid[i][j] == 0){
                    dfs(grid, vis, i, j, n, m);
                }
            }
        }
        cout<< "---------------------------------------"<<endl;
        int res = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    cout<<"Increasing res value for i="<<i<<"and j ="<<j<<endl;
                    res++;
                    cout<<"Res = "<<res<<"vis[i][j]="<<vis[i][j]<<"grid[i][j]="<<grid[i][j]<<endl;
                    dfs(grid, vis, i, j, n, m);
                }
            }
        }
        
        return res;
    }
};
```
