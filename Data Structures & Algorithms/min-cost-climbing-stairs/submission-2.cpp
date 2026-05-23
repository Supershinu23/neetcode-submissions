class Solution {
public:
    int func(int curr, vector<int> &cost, vector<int> &dp){
        if(curr==0 || curr==1)return cost[curr];
        if(dp[curr]!=-1)return dp[curr];
        return dp[curr] =cost[curr]+min(func(curr-1, cost, dp), func(curr-2, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<n;i++){
            dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-2], dp[n-1]);
    }
};
