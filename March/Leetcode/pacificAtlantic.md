#### Pacific Atlantic

```
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }
    void bfs(vector<vector<int>>& heights, int n, int m, vector<vector<bool>>& vis, queue<pair<int, int>>& q){
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int a = top.first;
            int b = top.second;
            vis[a][b] = true;
            for(int t =0; t<4; t++){
                int x = a+dx[t];
                int y = b+dy[t];
                if(isValid(x, y, n, m) && heights[x][y] >= heights[a][b] && !vis[x][y]){
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        queue<pair<int, int>> atlantic;
        queue<pair<int, int>> pacific;
        vector<vector<int>> ans;
        vector<vector<bool>> visA(n, vector<bool>(m, false));
        vector<vector<bool>> visP(n, vector<bool>(m, false));
        
        for(int i =0; i<m; i++){
            pacific.push({0, i});
            atlantic.push({n-1, i});
        }
        
        for(int i =0; i<n-1; i++){
            pacific.push({ i+1,0});
            atlantic.push({i, m-1});
        }
        
        bfs(heights, n, m, visA, atlantic);
        
        bfs(heights, n, m, visP, pacific);
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(visA[i][j] && visP[i][j]){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};

Time Complexity = O(V+E)
V = n*m
E = 4*n*m

= O(n*m)
```
