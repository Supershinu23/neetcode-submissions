class Solution {
public:
    int func(string s, int ind, vector<int> & dp){
        if(s[ind]=='0')return 0 ;
        if(ind>=s.size())return 1;
        if(dp[ind]!=-1)return dp[ind];
        int takeOne = func(s, ind+1, dp);

        int takeTwo = 0 ;
        if(ind+1<s.size() && stoi(s.substr(ind, 2)) >=10 && stoi(s.substr(ind, 2)) <=26 ){
            takeTwo = func(s, ind+2, dp);
        }
        return dp[ind] = takeOne+takeTwo;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return func(s, 0, dp);
    }
};
