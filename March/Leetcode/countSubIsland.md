### Count Sub Islands

```
class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i< 0 || i== grid2.size() || j<0 || j==grid2[0].size() || grid2[i][j] == 0){
            return true;
        }
        if(grid2[i][j] == 1 && grid1[i][j] == 0){
            return false;
        }
        grid2[i][j] = 0;
        auto up = dfs(grid1, grid2, i-1, j);
        auto down = dfs(grid1, grid2, i+1, j);
        auto left = dfs(grid1, grid2, i, j-1);
        auto right = dfs(grid1, grid2, i, j+1);
        return up&down&left&right;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for(int i =0; i<grid2.size(); i++){
            for(int j =0; j<grid2[0].size(); j++){
                if(grid2[i][j] == 1){
                   auto res = dfs(grid1, grid2, i, j);
                    if(res){
                        count++;
                    } 
                }
                
            }
        }
        return count;
    }
};
```
