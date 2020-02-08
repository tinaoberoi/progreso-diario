#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> dp(n, 1);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    for(int i = 0; i<n; i++){
        cout<<v[i]<<" ";
    }
    for(int i = 0; i<n; i++){
        cout<<dp[i]<<" ";
    }
    for(int i =1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(v[i]>v[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end())<<endl;
    return 0;
}