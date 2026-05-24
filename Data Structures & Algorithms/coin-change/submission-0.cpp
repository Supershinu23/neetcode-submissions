class Solution {
public:
    int func(vector<int> &coins, int curr, vector<vector<int>> &dp, int amount){

        if(amount==0)return 0;
        if(curr<0)return 1e9;
        if(dp[curr][amount]!=-1)return dp[curr][amount];

        int nottake = func(coins, curr-1, dp, amount);
        int take = 1e9;
        if(amount>=coins[curr]){
            take = 1+func(coins, curr, dp, amount-coins[curr]);
        }
        return dp[curr][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = func(coins, n-1, dp, amount);
        if(ans == 1e9)return -1;
        return ans;
    }
};
