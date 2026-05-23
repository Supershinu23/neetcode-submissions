class Solution {
public:
/* memoization----------->
    int func(int curr, vector<int> &cost, vector<int> &dp){
        if(curr==0 || curr==1)return cost[curr];
        if(dp[curr]!=-1)return dp[curr];
        return dp[curr] =cost[curr]+min(func(curr-1, cost, dp), func(curr-2, cost, dp));
    }
*/
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev1 = cost[0];
        int prev2 = cost[1];

        for(int i=2;i<n;i++){
            int c = cost[i]+min(prev1,prev2);
            prev1 = prev2;
            prev2 = c;
        }
        return min(prev1, prev2);
    }
};
