### Lazy salesman

```
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
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, w;
        cin>>n>>w;
        vector<int> a(n);
        for(int i =0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int count = 0;
        for(int i =0; i<n; i++){
            if(a[i] >= w){
                count++;
                break;
            }
            w = w-a[i];
            count++;
        }
        int remainDays = n - count;
        cout<<remainDays<<endl;
    }
    return 0;
}

```
