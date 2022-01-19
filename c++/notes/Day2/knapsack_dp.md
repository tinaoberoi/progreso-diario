####The dp Tabular approach to knapsack problem

```
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
using li = long long;
//int N = 1e9;
//vector<int> arr(N, 0);
void solve(li W, li N, li wt[], li val[]){
    vector<vector<li>> dp(N+1, vector<li>(W+1, 0));
    for(li i =0; i<=N; i++){
        for(li j=0; j<=W; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(wt[i-1] <=j){
                dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout<< dp[N][W]<<endl;
}


int main(int argc, const char * argv[]) {
    li W, N;
    cin>>N>>W;
    li wt[N];
    li val[N];
    for(li i =0; i<N; i++){
        cin>>wt[i]>>val[i];
    }
    solve(W, N, wt, val);
    return 0;
}
```