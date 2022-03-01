#### Flood Fill problem

```
class Solution {
public:
    bool isValid(int i, int j, int m , int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        return true;
    }
    void dfs (vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& vis, int m , int n){
        vis[sr][sc] = true;
        image[sr][sc] = newColor;
        cout<<"Coloring new color to "<<sr<<"and"<<sc<<"->"<<image[sr][sc]<<endl;
        if(isValid(sr+1, sc, m, n)){
            if(!vis[sr+1][sc] && image[sr+1][sc] != 0){
                cout<<"sr+1 and sc are valid"<<sr+1<<" "<<sc<<endl;
                dfs(image, sr+1, sc, newColor, vis, m, n);
            }
        } if (isValid(sr, sc+1, m, n)){
            if(!vis[sr][sc+1] && image[sr][sc+1] != 0){
                cout<<"sr and sc+1 are valid"<<sr<<" "<<sc+1<<endl;
                dfs(image, sr, sc+1, newColor, vis, m, n);
            }
        } if (isValid(sr-1, sc, m, n) ){
            if(!vis[sr-1][sc] && image[sr-1][sc] != 0){
                cout<<"sr-1 and sc are valid"<<sr-1<<" "<<sc<<endl;
                dfs(image, sr-1, sc, newColor, vis, m, n);
            }
        } if (isValid(sr, sc-1, m , n)){
            if(!vis[sr][sc-1] && image[sr][sc-1] != 0){
                cout<<"sr and sc-1 are valid"<<sr<<" "<<sc-1<<endl;
                dfs(image, sr, sc-1, newColor, vis, m, n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        if(image[sr][sc] != newColor){
            dfs(image, sr-1, sc-1, newColor, vis, m, n);
        }
        cout<<"sr="<<sr<<"sc="<<sc<<endl;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                cout<<image[i][j]<<" ";
            }
            cout<<endl;
        }
        return image;
    }
};
```