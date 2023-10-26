###### Perfect Permutation

Approach: since every number is divisible by I =1;
          Leave k-1 elements from the end as they are
          4th element from last should be swapped
          Eg: n = 6, k =2
          Last k-1 = 1 element should be as it is
          assign 4th from last from 1
          1 2 3 4 5 6 -> 5 2 3 4 5 6, temp = 1;
          And then shift the rest
          5 1 2 3 4 6

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
        int range = n-k;
        if(n != k){
            int temp = a[1];
            a[1] = a[n-(k-1)];
            
            for(int i =2; i<=(n-k+1); i++){
                int temp2 = a[i];
                a[i] = temp;
                temp = temp2;
            }
        }
        
        for(int i = 1; i<=n; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
```