class Solution {
public:
    bool func(int curr, vector<int> &nums, vector<int>&dp){
        if(curr>=nums.size()-1){return true;}
        if(dp[curr]!= -1)return dp[curr];

        int flag= false;
        for(int i=0;i<nums[curr];i++){
            flag = flag || func(curr+i+1, nums, dp);
        }
        return dp[curr] = flag ;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return func(0, nums, dp);
    }
};
