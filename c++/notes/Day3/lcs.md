##### Longest common subsequence

- Memoization Method

```
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
#include<cstring>
using namespace std;
using li = long long;
//int N = 1e9;
//vector<int> arr(N, 0);
string s ="";
int solveRec(string s1, string s2, int i, int j, int** dp){
    if(i<0 || j<0)
        return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    else if(s1[i] == s2[j]){
        dp[i][j] = 1+solveRec(s1, s2, i-1, j-1, dp);
        return dp[i][j];
    }
    else{
        dp[i][j] = max(solveRec(s1, s2, i-1, j, dp), solveRec(s1, s2, i, j-1, dp));
    }
    return dp[i][j];
}

void solve(string s1, string s2, int m, int n){
    int** dp;
    dp = new int*[m+1];
    for(int i =0; i<n; i++){
        dp[i] = new int[n];
    }
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            dp[i][j] = -1;
        }
    }
    int index = solveRec(s1, s2, m-1, n-1, dp);
    int i =m, j=n;
    
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            s+=s1[i-1];
            i--;j--;
            
        } else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<reverse(s.begin(), s.end())<<endl;
}


int main(int argc, const char * argv[]) {
    string s1, s2;
    cin>>s1>>s2;
    int len1 = s1.size();
    int len2 = s2.size();
    solve(s1, s2, len1, len2);
    //cout<<s<<endl;
    return 0;
}

```

- Tabular Method

```
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
//int N = 1e9;
//vector<int> arr(N, 0);
string s ="";
int solveRec(string s1, string s2, int i, int j, int** dp){
    if(i < 0 || j<0){
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    else if(s1[i] == s2[j]){
        dp[i][j] = max(solveRec(s1, s2,i-1, j-1, dp)+1,
                       max(solveRec(s1, s2, i-1, j, dp),
                       solveRec(s1, s2, i, j-1, dp)));
    } else {
        dp[i][j] = max(solveRec(s1, s2,i-1, j-1, dp),
                       max(solveRec(s1, s2, i-1, j, dp),
                           solveRec(s1, s2, i, j-1, dp)));
    }
    return dp[i][j];
}

void solve(string s1, string s2, int len1, int len2){
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    for(int i =0; i<len1+1; i++){
        for(int j =0; j<len2+1; j++){
            if(i ==0 || j==0){
                dp[i][j] = 0;
            } else if (s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    int index = dp[len1][len2];
    char lcs[index+1];
    lcs[index] = '\0';
    int i = len1, j = len2;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            lcs[index-1] = s1[i-1];
            //cout<<s1[i-1]<<"&i"<<i<<endl;
            i--;
            j--;
            index--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        } else {
            j--;
        }
    }
    cout<<lcs<<endl;
}


int main(int argc, const char * argv[]) {
    string s1, s2;
    cin>>s1>>s2;
    int len1 = s1.size();
    int len2 = s2.size();
    solve(s1, s2, len1, len2);
    //cout<<s<<endl;
    return 0;
}
```