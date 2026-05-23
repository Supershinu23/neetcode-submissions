class Solution {
public:
    string longestPalindrome(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        string ans  = "";
        int max = 0 ;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                int orginal_start = i-dp[i][j];
                int reversed_start = n-j;
                if(dp[i][j]!=0 && dp[i][j]>max && orginal_start==reversed_start){
                    ans = s.substr(i-dp[i][j], dp[i][j]);
                    max = dp[i][j];
                }
            }
        }
        return ans ;
    }
};
