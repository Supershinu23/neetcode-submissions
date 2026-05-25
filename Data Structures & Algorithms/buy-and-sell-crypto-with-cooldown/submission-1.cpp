class Solution {
public:
    int func(int curr, vector<int>& prices, int canBuy, vector<vector<vector<int>>>&dp){
        if(curr>=prices.size())return 0 ;
        int profit = 0 ;
        if(dp[curr][canBuy][prices[curr]]!=-1)return dp[curr][canBuy][prices[curr]];
        if(canBuy){
            int buy = -1* prices[curr] + func(curr+1, prices, 0, dp);
            int notBuy = func(curr+1, prices, 1, dp);
            profit = max(buy, notBuy);
        }else{
            int sell = prices[curr]+func(curr+2, prices, 1, dp);
            int notSell = func(curr+1, prices, 0, dp);
            profit = max(sell, notSell);
        }
        return dp[curr][canBuy][prices[curr]] = max(profit, 0);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(1000+1, -1)));
        return func(0, prices, 1, dp);
    }
};
