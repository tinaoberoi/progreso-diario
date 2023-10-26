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
int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
const int inf = 1e9 + 7;
class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>= m){
            return false;
        }
        return true;
    }
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dist, int i, int j, int n, int m){
        queue<pair<int, int>> q;
        q.push({i, j});
        dist[0][0] = 0;
        grid[i][j] = 1;
        while(!q.empty()){
            auto top = q.front();
            int a = top.first;
            int b = top.second;
            q.pop();
            //cout<<"Popped elements a = "<<a<<" b ="<<b<<endl;
            for(auto t =0; t<8; t++){
                int x = a+dx[t];
                int y = b+dy[t];
                //cout<<"Sub elements of a = "<<a<<" and b = "<<b<<"--> x = "<<x<<" y ="<<y<<endl;
                if(isValid(x, y, n, m) && grid[x][y] == 0){
                    q.push({x, y});
                    //cout<<"Pushed elements x = "<<x<<"and y ="<<y<<endl;
                    //cout<<"dist[a][b] = "<<dist[a][b]<<endl;
                    dist[x][y] = dist[a][b] + 1;
                    //cout<<"dist[x][y] = "<<dist[x][y]<<endl;
                    grid[x][y] = 1;
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, inf));
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                bfs(grid, dist, i, j, n, m);
            }
        }
        
        int ans = dist[n-1][m-1];
        //cout<<"--------"<<dist[n-1][m-1]<<"------------"<<endl;
        if(ans >= inf)
            return -1;
        else 
            return ans+1;
    }
};
```
Ps: Need for a for loop for cases like:
[[0,1,1,0,0,0],[0,1,0,1,1,0],[0,1,1,0,1,0],[0,0,0,1,1,0],[1,1,1,1,1,0],[1,1,1,1,1,0]]

