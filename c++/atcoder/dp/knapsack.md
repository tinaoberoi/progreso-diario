#####Knapsack problem
N items, max weight W. What items to choose to have maximum profit

Method 1: Recurrsive Solution
In this there can be two possibility for every item
- chosen in optimal solution
- not chosen in optional solution

Lets consider for last element
- Last element chosen: that means I need to find elements with max profit of weight W- wt[N-1] from remaining N-1
- Last element not chosen: that means I need to maximise profit from N-1 with weight W.

Take max of the two situations

```
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
using li = long long;
//int N = 1e9;
//vector<int> arr(N, 0);
int solve(int W, int N, int wt[], int val[]){
    if(W == 0 || N == 0){
        return 0;
    }
    if(W < wt[N-1]){
        return solve(W, N-1, wt, val);
    } else {
        return max(solve(W, N-1, wt, val),
                   val[N-1]+solve(W-wt[N-1], N-1, wt, val));
    }
        
    return 0;
}


int main(int argc, const char * argv[]) {
    int W, N;
    cin>>N>>W;
    int wt[N];
    int val[N];
    for(int i =0; i<N; i++){
        cin>>wt[i]>>val[i];
    }
    cout<<solve(W, N, wt, val)<<endl;
    return 0;
}
```

TimeComplexity : O(2^n)
SpaceComplexity = O(1)