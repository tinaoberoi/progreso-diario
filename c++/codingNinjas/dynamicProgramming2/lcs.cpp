#include <bits/stdc++.h>

using namespace std;

//Exponential Complexity
int lcsNaive(string s, string t)
{
    int ans = 0;
    if(s[0] == '\0' || t[0] == '\0')
        return 0;
	//Write your code here
    if(s[0] == t[0])
        return 1+lcs(s.substr(1), t.substr(1));
    else {
        return max(lcs(s.substr(1), t), lcs(s, t.substr(1)));
    }
    return ans;
}

int lcsHelperRecursive(string s, string t, int m, int n, int** dp){
    if(m == 0 || n == 0)
        return 0;
    if(dp[m][n] > -1)
        return dp[m][n];
    int ans;
    if(s[0] == t[0])
        ans = 1+lcsHelperRecursive(s.substr(1), t.substr(1), m-1, n-1, dp);
    else{
        int option1 = lcsHelperRecursive(s.substr(1), t, m-1, n, dp);
        int option2 = lcsHelperRecursive(s, t.substr(1), m, n-1, dp);
        ans = max(option1, option2);
    }
    dp[m][n] = ans;
    return ans;
}

int lcsRecursive(string s, string t)
{
    int m = s.length();
    int n = t.length();
    
    int ** dp = new int*[m+1];
    for(int i =0; i<=m; i++){
        dp[i] = new int[n+1];
        for(int j =0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    
    int ans = lcsHelperRecursive(s, t, m, n, dp);
    for(int i =0; i<=m; i++){
        delete [] dp[i];
    }
    delete dp;
    return ans;
}

int lcsIterative(string s, string t)
{
    //Write your code here
    int m = s.length();
    int n = t.length();
    int** dp = new int*[m+1];
    for(int i = 0; i<=m; i++){
        dp[i] = new int[n+1];
    }
    
    for(int i =0; i<=n; i++){
        dp[0][i] = 0;
    }
    for(int i =0; i<=m; i++){
        dp[i][0] = 0;
    }
    
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[m-i] == t[n-j]){
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s; 
    string t;

    cin >> s;
    cin >> t;

    cout << lcs(s, t) << endl;
}