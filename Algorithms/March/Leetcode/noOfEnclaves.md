#### Number of Enclaves
https://leetcode.com/problems/number-of-enclaves/
Approach:
- Go through each node on the corner and mark those as 0
- Count the remaining nodes, these are the ones not accessibe from the boundary thus not changed to 0 in the prev step
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
    void dfsUtil(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m){
        //cout<<"DFS for i ="<<i<<"and j ="<<j<<endl;
        vis[i][j] = true;
        grid[i][j] = 0;
        for(int t =0; t<4; t++){
            int x = i+dx[t];
            int y = j+dy[t];
            //cout<<"Checking for x = "<<x<<"y= "<<y<<endl;
            if(isValid(x, y, n, m) && !vis[x][y] && grid[x][y] == 1 ){
                //cout<<"Callling dfs value for x = "<<x<<"y="<<y<<endl;
                dfsUtil(grid, vis, x, y, n, m);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int max_count = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if((i*j == 0 || i == n-1 || j == m-1) && !vis[i][j] && grid[i][j] == 1){
                    //cout<<"Running DFS for i = "<<i<<"and j = "<<j<<"vis[i][j]"<<vis[i][j]<<endl;
                    dfsUtil(grid, vis, i, j, n, m);
                }
            }
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    max_count++;
                }
            }
        }
        return max_count;
    }
};
```
