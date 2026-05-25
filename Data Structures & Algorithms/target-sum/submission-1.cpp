class Solution {
public:
    int func(int curr, vector<int> &nums, int target, vector<vector<int>> & dp){
        
        if(curr<0){
            if(target==0)return 1;
            return 0 ;}

        if(dp[curr][target]!=-1)return dp[curr][target];
        int notTake = func(curr-1, nums, target, dp);
        int take= 0 ;
        if(target>=nums[curr]){
            take = func(curr-1, nums, target-nums[curr], dp);
        }
        return dp[curr][target] = take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0 ;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if((sum+target)%2==1)return 0 ;
        target = (sum+target)/2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return func(n-1, nums, target, dp);
    }
};
