### Fibonacii 

Tabulation
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
Time Complexity: O(n)
Space Complexity: O(n)

Recursive

```
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iomanip>

using namespace std;
vector<int> dp;

int fib (int n){
    if(n == 0)
        return 0;
    if(dp[n] != 0)
        return dp[n];
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp.resize(n+1, 0);
    dp[1] = dp [2] = 1;
    cout<<fib(n)<<endl;
    return 0;
}

```
Time Complexity: O(2^n)
Space Complexity: O(n)