#### Coins problem
https://atcoder.jp/contests/dp/tasks/dp_i
Solution: 
First write a recursive solution (draw a tree) and then improve efficiency by storing in dp
```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;
vector<vector<double>> dp;
vector<vector<int>> maze;
vector<double> p;

double coins(int i, int nt, int nh, int n){
    if(dp[nt][nh] != -1)
        return dp[nt][nh];
    if(nt >= n/2 +1)
        return 0;
    if(n-i < 0)
        return 0;
    if(n-i == 0)
        return 1;
    //cout<<"i="<<i<<" nt="<<nt<<" nh="<<nh<<" n="<<n<<endl;
    double heads = coins(i+1, nt, nh+1, n);
    double tails = coins(i+1, nt+1, nh, n);
    //cout<<"p[i+1]="<<p[i+1]<<endl;
    double ans = p[i+1]*heads + (1-p[i+1])*tails;
    dp[nt][nh]= ans;
    return dp[nt][nh];
}

int main(){
    int n;
    cin>>n;
    p.resize(n+1);
    dp.resize(n+1, vector<double>(n+1, -1));
    for(int i =1; i<=n; i++){
        cin>>p[i];
    }
    /*
    for(int i =1; i<=n; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    */
    cout<<setprecision(11)<<coins(0, 0, 0, n)<<endl;
    /*
    for(int i =0; i<=n; i++){
        for(int j =0; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }
    }*/
}
```