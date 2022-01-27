####The dp Tabular approach to knapsack problem

The reduce the complexity of a recursive solution
We can store rather than computing repeated values
Method: Tabular
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
Memoization Method:
- we will modify the recursive solution.
- Whenever dp[I][W] is not -1 that means it was filled return
- every time you solve and find out store the value of recurrsive function

```
//
//  main.cpp
//  HelloWorld
//
//  Created by Tina Oberoi on 08/01/22.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
using li = long long;
//int N = 1e9;
//vector<int> arr(N, 0);

li solveRec(li W, li wt[], li val[], li** dp, li i){
    if(i < 0){
        return 0LL;
    }
    if(dp[i][W] != -1)
        return dp[i][W];
    if(wt[i]> W){
        dp[i][W] = solveRec(W, wt, val,dp, i-1);
        return dp[i][W];
    } else {
        dp[i][W] = max(solveRec(W, wt, val,dp, i-1), val[i] + solveRec(W-wt[i], wt, val, dp, i-1));
    }
    return dp[i][W];
}

void solve(li W, li N, li wt[], li val[]){
    
    li** dp;
    dp = new li*[N];
 
    // loop to create the table dynamically
    for (li i = 0; i < N; i++)
        dp[i] = new li[W + 1];
 
    // loop to initially filled the
    // table with -1
    for (li i = 0; i < N; i++)
        for (li j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    cout<<solveRec(W, wt, val, dp, N-1)<<endl;
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