class Solution {
public:
    bool func(vector<int> &nums, int curr, int target, vector<vector<int>> &dp){
        if(target==0)return true;
        if(curr<0)return false;
        if(dp[curr][target]!=-1)return dp[curr][target] ;
        int nottake = func(nums, curr-1, target, dp);
        int take = false ;

        if(target>=nums[curr]){
            take = func(nums, curr-1, target-nums[curr], dp);
        }
        return dp[curr][target] = take || nottake ;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 == 1)return false;
        sum/=2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return func(nums, n-1, sum, dp);
    }
};
