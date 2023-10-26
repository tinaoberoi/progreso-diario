```
class Solution {
public:
    void paint(vector<vector<int>>& A, int i, int j) {
        int n = A.size();
        if(i < 0 || j< 0 || i>= n || j >= n)
            return;
        if(A[i][j] != 1)
            return;
        A[i][j] = 2;
        paint(A, i, j-1);
        paint(A, i+1, j);
        paint(A, i-1, j);
        paint(A, i, j+1);
    }
    
    bool expand(vector<vector<int>>& A, int i, int j, int cl) {
        int n = A.size();
        if(i < 0 || j< 0 || i>= n || j >= n)
            return false;
        if(A[i][j] == 0)
            A[i][j] = cl+1;
        if(A[i][j] == 1)
            return true;
        return false;
    }
    void paint(vector<vector<int>>& A){
        int n = A.size();
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(A[i][j] == 1){
                    paint(A, i, j);
                    return;
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        paint(grid);
        
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int cl = 2;; cl++){
            for(int i =0; i<n; i++){
                for(int j =0; j<n; j++){
                    if(grid[i][j] == cl ){
                        if(expand(grid, i-1, j, cl ) || expand(grid, i+1, j, cl ) || expand(grid, i, j-1, cl ) ||
                      expand(grid, i, j+1, cl )){
                        return cl-2;
                    }}
                }
            }
        }
    }
};
```
