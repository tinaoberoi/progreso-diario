/**/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> rect;
vector<vector<int>> dp;

int n, m;

int kandane(vector<int> temp, int *start, int *finish, int r){
	int sum = 0, max_sum = INT_MIN, i;
	*finish = -1;
	int local_start = 0;

	for(i =0; i<n; i++){
		sum+=temp[i];
		if(sum<0){
			sum = 0;
			local_start = i+1;
		}else{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if(finish != -1)
		return maxSum;

	maxSum = temp[0];
	*start= *finish = 0;

	for(i =1; i<n; i++){
		if(temp[i] > maxSum){
			maxSum = temp[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

int finalMaxSum(){
	int maxSum = INT_MIN, finalleft, finalright, finaltop, finalbottom;

	int left, right, i;
	vector<int> temp;
	int sum, start, finish;

	for(left = 0; left < m; left++){
		temp.clear();
		temp.resize(n, 0);
		for(right = left; right<m; right++){
			for(i = 0; i<n; i++){
				temp[i] +=rect[i][right];
			}
			sum = kandane(temp, &start, &finish, n);

			if(sum > maxSum){
				maxSum = sum;
				finalleft = left;
				finalright = right;
				finaltop = start;
				finalbottom = finish;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	rect.clear();
	rect.resize(n, vector<int>(m));
	
	for(int i =0; i<n; i++){
		for(int j =0; j<m; j++){
			cin>>rect[i][j];
		}
	}
	
	cout<<finalMaxSum();

	return 0;
}