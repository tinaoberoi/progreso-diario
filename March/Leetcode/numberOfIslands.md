### Number of Islands
https://leetcode.com/problems/number-of-islands/
```
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
class Solution {
public:
    
    bool isValid(int x, int y, int n, int m){
        if(x<0 || x>=n || y<0 || y>=m){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m, vector<vector<bool>>& vis){
        //cout<<"i="<<i<<"j="<<j<<endl;
        vis[i][j] = true;
        for(auto t =0; t<4; t++){
            int x = i+dx[t];
            int y = j+dy[t];
            //cout<<"x="<<x<<"y="<<y<<endl;
            if(isValid(x, y, n, m) && !vis[x][y]){
                if(grid[x][y] == grid[i][j]){
                    //cout<<"grid[x][y]"<<grid[x][y]<<endl;
                    //cout<<"Turns out x and y is Valid"<<endl;
                    dfs(grid, x, y, n, m, vis);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        int temp =0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != '0'){
                    //cout<<"grid[i][j]"<<grid[i][j]<<endl;
                    dfs(grid, i, j, n, m, vis);
                    //cout<<"Increasing count from "<<count<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};
```
