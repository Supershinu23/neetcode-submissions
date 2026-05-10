class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s ;
        int n = prices.size();
        int ans = 0 ;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=prices[i])s.pop();

            if(!s.empty()){
                ans = max(ans, s.top()-prices[i]);
            }else{
                s.push(prices[i]);
            }
        }
        return ans;
    }
};
