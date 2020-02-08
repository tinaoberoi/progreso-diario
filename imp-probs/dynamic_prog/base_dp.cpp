#include <bits/stdc++.h>
using namespace std;
vector <int> dp,input;

int func(int idx)
{
  if(idx == input.size()-1)  return 0;
  if(idx >= input.size()) return INT_MAX;
  if(dp[idx] != -1) return dp[idx];
  int result = min(func(idx+1)+abs(input[i]-input[i+1]),func(idx+2)+abs(input[i]-input[i+1]));
  return dp[idx] = result;
}
int main()
{
    int n;cin>>n;
    input.clear();
  	input.resize(n);
  	dp.clear();
  	dp.resize(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
   	cout<<func(0);
  	return 0;
} 
