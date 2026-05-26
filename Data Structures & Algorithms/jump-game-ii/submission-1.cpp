class Solution {
public:
    int func(int curr, vector<int> &nums, vector<int> &dp){
        if(curr>=nums.size()-1)return 0;
        if(dp[curr]!=-1)return dp[curr];

        int ans = INT_MAX;

        for(int i=0;i<nums[curr];i++){
            if(curr+i+1<nums.size()){
                ans = min(ans, func(curr+i+1, nums, dp));
            }
        }
        if(ans==INT_MAX)return ans;
        return dp[curr] = 1+ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return func(0, nums, dp);
    }
};
