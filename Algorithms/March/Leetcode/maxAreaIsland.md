#### Max Area Island
https://leetcode.com/problems/max-area-of-island/
```
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    int dfs(vector<vector<int>>& grid, int n, int m, int i, int j, int count, vector<vector<bool>>& vis){
        vis[i][j] = true;
        cout<<"Running dfs for i = "<<i<<"j = "<<j<<endl;
        for(auto t = 0; t<4; t++){
            int x = i+dx[t];
            int y = j+dy[t];
            cout<<"x="<<x<<"y="<<y<<endl;
            if(isValid(x, y, n, m) && !vis[x][y] && grid[x][y] != 0){
                cout<<"x="<<x<<"and y="<<y<<"is valid"<<endl;
                int res = dfs(grid, n, m, x, y, count+1, vis);
                cout<<"Returned count = "<<res<<endl;
                count = max(count, res);
                cout<<"Count value now is "<<count<<endl;
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    cout<<"running dfs on i="<<i<<"j="<<j<<endl;
                    int count_now = dfs(grid, n, m, i, j, 1, vis);
                    cout<<"count_now="<<count_now<<endl;
                    max_count = max(max_count, count_now);
                    cout<<"Updated max_count is = "<<max_count<<endl;
                }
            }
        }
        if(max_count > 0)
            return max_count;
        else
            return 0;
    }
};
```
