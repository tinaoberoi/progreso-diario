### Fibonacii 

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;
vector<int> dp;

int main(){
    int n;
    cin>>n;
    dp.resize(n+1, 0);
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i =3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl;
    return 0;
}

```