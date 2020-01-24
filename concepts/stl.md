# STL

## lower bound and upper bound

* lower_bound => returns iterator pointing to first element in range [first, last) which has a value not less than 'val'.
* upper_bound => return iterator pointing to first element in range [first, last) which has a value greater than 'val'. 

```c++
#include <iostream> 
#include <algorithm>    // for lower_bound, upper_bound and sort 
#include <vector>       // for vector 
  
using namespace std; 
  
int main () 
{ 
    int gfg[] = {5,6,7,7,6,5,5,6}; 
      
    vector<int> v(gfg,gfg+8);    // 5 6 7 7 6 5 5 6 
  
    sort (v.begin(), v.end());  // 5 5 5 6 6 6 7 7 
  
    vector<int>::iterator lower,upper; 
    lower = lower_bound (v.begin(), v.end(), 6);  
    upper = upper_bound (v.begin(), v.end(), 6);  
  
    cout << "lower_bound for 6 at position " << (lower- v.begin()) << '\n'; 
    cout << "upper_bound for 6 at position " << (upper - v.begin()) << '\n'; 
  
    return 0; 
} 
```

> **Output**
Quote break.
> lower_bound for 6 at position 3
Quote break.
> upper_bound for 6 at position 6