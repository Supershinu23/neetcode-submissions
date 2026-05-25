class Solution {
public:
    int func(int curr, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount==0)return 1;
        if(curr<0)return 0;
        if(dp[curr][amount]!= -1)return dp[curr][amount];
        int notTake = func(curr-1, amount, coins, dp);
        int take = 0 ;
        if(amount>=coins[curr]){
            take  = func(curr, amount-coins[curr], coins, dp);
        }
        return dp[curr][amount] = take+notTake ;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};
