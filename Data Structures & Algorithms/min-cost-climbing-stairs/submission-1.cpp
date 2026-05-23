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
        if(cost.size()<2)return func(cost.size()-1, cost,dp);
        return min(func(cost.size()-1, cost, dp), func(cost.size()-2, cost, dp));
    }
};
