/*
 I/P
 5 7
 S . . # . . .
 . # . . . # .
 . # . . . . .
 . . # # . . .
 # . # E . # .
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n+1];
        for(int i = 1; i<=n; i++) a[i] = i;
        if(k != n){
            int x = n-k;
            for(int i = k+1; i+1<=n; i+=2){
                swap(a[i], a[i+1]);
            }
            if(x%2){
                swap(a[1], a[n]);
            }
        }
        
        for(int i = 1; i<=n; i++) cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}

