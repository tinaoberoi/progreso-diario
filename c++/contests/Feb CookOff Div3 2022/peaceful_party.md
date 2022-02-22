### Peaceful Party

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

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int pa, pb, pc;
        cin>>pa>>pb>>pc;
        
        int sum = pa + pc;
        
        if(sum > pb){
            cout<<sum<<endl;
        } else {
            cout<<pb<<endl;
        }
    }
    return 0;
}

```
