#include <bits/stdc++.h>
using namespace std;
#define vt vector

//3
//1 2 3 
//4

//size[{1,1,1,1},{1,1,2} ,{2,2},{1,3},{3,1},{1,2,1},{2,1,1}] === 7
vector<int>dp(1000,-1);
int combinationSum4(vector<int>& nums, int target) {
	if(dp[target] == -1)
	{
	if(target == 0) return 1;
	
	dp[target] = 0;
	
	for(auto& num : nums)
		if(num <= target) dp[target] += combinationSum4(nums, target - num);
	}
	return dp[target];  
}
int main(){
	int n ;cin>>n;
	vt<int>nums(n);int target;
	for(int i = 0;i<n;i++)cin>>nums[i];
	
	cin>>target;	
	cout<<combinationSum4(nums,target)<<"\n";
}
