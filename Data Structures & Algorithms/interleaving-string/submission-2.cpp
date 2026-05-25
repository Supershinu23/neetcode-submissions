class Solution {
public:
    bool func(int i, int j, int k, string s1, string s2, string s3, vector<vector<vector<int>>> &dp){
        if(i>=s1.size()){
            return s2.substr(j, s2.size()-j)==s3.substr(k, s3.size()-k);
        }
        if(j>=s2.size()){
            return s1.substr(i, s1.size()-i)==s3.substr(k, s3.size()-k);
        }
        // if(s1[i]!=s3[k] || s2[j]!=s3[k])return false;
        if(dp[i][j][k]!= -1)return dp[i][j][k];
        int t1 = false, t2 = false;
        if(s1[i]==s3[k]){
            t1 = func(i+1, j, k+1, s1, s2, s3,dp) ;
        }
        if(s2[j] == s3[k]){
            t2 = func(i, j+1, k+1, s1, s2, s3, dp);
        }
        return dp[i][j][k] = t1 || t2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1,-1)));
        return func(0,0,0,s1,s2,s3, dp);
    }
};
