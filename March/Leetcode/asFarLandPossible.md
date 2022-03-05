### As Far Land as possible

Approach1:
- Apply BFS on every 0 and find the one with max dist to nearest 1
- here nearest 1 could be found using bfs
```
int dx[] = {-1, 1,0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
public:
    int calcDist(int x1, int y1, int x2, int y2){
        return (abs(x1-x2) + abs(y1-y2));
    }
    bool isValid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        int dist = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        //vis[0][0] = true;
        //cout<<"Checking for i="<<i<<" j="<<j<<"grid[i][j]"<<grid[i][j]<<endl;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int a = temp.first;
            int b = temp.second;
            for(auto t = 0; t<4; t++){
                int x = a+dx[t];
                int y = b+dy[t];
                
                if(isValid(x, y, grid.size(), grid[0].size())){
                    if(grid[x][y] == 1){
                        //cout<<"Qualified x="<<x<<"and y="<<y<<endl;
                        dist = calcDist(i, j, x, y);
                        //cout<<"dist = "<<dist<<endl;
                        return dist;
                    }
                    q.push({x, y});
                }
            }
        }
        return dist;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_dist = 0;
        vector<vector<bool>> vis (n, vector<bool>(m, false));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 0){
                    int count = bfs(grid, vis, i, j);
                    max_dist = max(count, max_dist);
                }
            }
        }
        return max_dist;
    }
};
```
Time Complexity: no Of zeroes * O(V+M)
V = n^2
E = 4n^2
no of zeroes = n2 (max)
https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/graphs/as_far_from_land_as_possible/topic


