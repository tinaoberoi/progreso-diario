/*https://leetcode.com/problems/jump-game-ii/*/
#include <bits/stdc++.h>
using namespace std;

// exponential time soln
/* DP Approach
int jump(vector<int>& nums) {
	int n = nums.size();
	vector<int> jumps(n);
	vector<int> src(n);
	jumps[0] = 0;
	src[0] = 0;
	int p1, p2; 
	p2 = 1;
	while(p2<n){
		jumps[p2] = INT_MAX;
		for(p1 = 0; p1<p2; p1++){
			if(p2 <= p1 + nums[p1] && jumps[p1] != INT_MAX){
		    	jumps[p2] = min(jumps[p2], jumps[p1] + 1);
		    	src[p2] = p1;
		    	break;
		    }
		}
		p2++;
	}
	for(int i =0; i<n; i++){
		cout<<"jumps to reach "<<i<<" is "<<jumps[i]<<" from "<<src[i]<<endl;
	}
	return jumps[n-1];
}

*/

// BFS Solution (https://leetcode.com/problems/jump-game-ii/discuss/18028/O(n)-BFS-solution)


int jump(vector<int>& nums){
	int n = nums.size();
	int curr_max = 0, level = 0, next_max = 0, i =0;

	while(curr_max - i >= 0){
		level++;
		for(;i<=curr_max; i++){
			next_max = max(next_max, nums[i] + i);
			if(next_max >= n-1) return level;
		}
		curr_max = next_max;
	}
	return 0;
}	
int main(){
	//freeopen("input.txt", "r", stdin);
	vector<int> v = {2,3,1,1,4};
	
	cout<<jump(v)<<endl;
	return 0;
}