/*
https://www.codechef.com/problems/CHEFRES
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<pair<int, int>> intervals(n);
        for(int i =0; i<n; i++){
            cin>>intervals[i].first>>intervals[i].second;
        }
        sort(intervals.begin(), intervals.end());

        while(m--){
            int p ;
            cin>>p;
            int pos = lower_bound(intervals.begin(), intervals.end(), make_pair(p,0)) - intervals.begin();
            
            if(pos == 0){
                int ans = intervals[0].first - p;
                cout<<ans<<endl;
            }else{
                int ans = -1;
                if(intervals[pos-1].second > p){
                    ans = 0;
                }else if(pos < n){
                    ans = intervals[pos].first - p;
                }
                cout<<ans<<endl;
            }
        }

    }
    return 0;
}