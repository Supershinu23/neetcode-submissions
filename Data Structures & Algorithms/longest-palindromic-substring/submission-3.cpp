class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        // string ans  = "";
        // int max = 0 ;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j]=dp[i-1][j-1]+1;
        //         }
        //         int orginal_start = i-dp[i][j];
        //         int reversed_start = n-j;
        //         if(dp[i][j]!=0 && dp[i][j]>max && orginal_start==reversed_start){
        //             ans = s.substr(i-dp[i][j], dp[i][j]);
        //             max = dp[i][j];
        //         }
        //     }
        // }

        int ind = 0 ;
        int maxLength = 0;
        for(int i=0;i<n;i++){
            int l = i, r = i ;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxLength){
                    ind = l ;
                    maxLength = r-l+1;
                }
                l--;
                r++;
            }

            // for even palindrome
            l = i, r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxLength){
                    ind = l ;
                    maxLength = r-l+1;
                }
                l--;
                r++;
            }
        }
        return  s.substr(ind, maxLength);
    }
};
