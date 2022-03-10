### 01 Matrix
```
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        return true;
    }
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& dist, int n, int m, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        int level = 0;
        mat[i][j] = 0;
        while(!q.empty()){
            auto top = q.front();
            int a = top.first;
            int b = top.second;
            level++;
            for(int t =0; t<4; t++){
                int x = a+dx[t];
                int y = b+dy[t];
                
                if(isValid(x, y, n, m)){
                    if(mat[x][y] == 0){
                        dist[a][b] = level;
                        return;
                    } else {
                        q.push({x, y});
                    }
                }
            }
        }
        return;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j] == 1){
                    bfs(mat, dist, n, m, i, j);
                    //mat[i][j] = 0;
                } else if(mat[i][j] == 0){
                    if(dist[i][j] == -1){
                        dist[i][j] = 0;
                    }
                }
            }
        }
        
        return dist;
    }
};
```
