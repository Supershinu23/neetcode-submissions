class Solution {
public:
    int func(vector<int> & nums, int curr, vector<int>&dp){
        if(curr<0)return 0;
        if(dp[curr]!= -1)return dp[curr];

        return dp[curr] = nums[curr]+ max(func(nums, curr-2, dp), func(nums, curr-3, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return max(func(nums, nums.size()-1, dp), func(nums, nums.size()-2, dp));
    }
};
