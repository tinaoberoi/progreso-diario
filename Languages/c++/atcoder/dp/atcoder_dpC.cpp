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
int N = 1e9;
//vector<int> arr(N, 0);
int solve(){
    int n;
    cin>>n;
    
    return 0;
}


int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i =0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>v[i][j];
        }
    }
    /*cout<<"Matrix formed is"<<endl;
    for(int i =0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for(int i =1; i<n; i++){
        dp[i][0] = v[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = v[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = v[i][2] + max(dp[i-1][1], dp[i-1][0]);
    }
    /*cout<<"printing dp values"<<endl;
    for(int i =0; i<n; i++){
        for(int j=0; j<3; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int ans = max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));
    cout<<ans<<endl;
    return 0;
}
