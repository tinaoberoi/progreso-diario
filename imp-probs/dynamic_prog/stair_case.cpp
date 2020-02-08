/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7*/
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
vector<int> dp;
long func(int n){
    if(n<=0)
        return 0;
    if(dp[n] != -1) return dp[n];
    
    long output = func(n-1) + func(n-2) + func(n-3);
    dp[n] = output;
    
    return dp[n];
}

long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    dp.clear();
    dp.resize(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i =0; i<n+1; i++){
        cout<<dp[i]<<endl;
    }
    return func(n);
    
}   

int main(){
    int n;
    cin>>n;
    cout<<staircase(n);
    return 0;
}