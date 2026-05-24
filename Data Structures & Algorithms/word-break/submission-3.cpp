class Solution {
public:
    unordered_set<string> wordSet;
    vector<int> memo;
    int t;
    bool func(int i, string &s){
        if(i==s.size())return true;

        if(memo[i]!=-1)return memo[i]==1;
        for(int j=i;j<(i+t, s.size()); j++){
            if(wordSet.count(s.substr(i, j-i+1))){
                if(func(j+1, s)){
                    memo[i]=1;
                    return true;
                }
            }
        }
        memo[i]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        wordSet.insert(wordDict.begin(), wordDict.end());
        memo.resize(s.size(), -1);
        t = 0 ;
        for(int i=0;i<wordDict.size();i++){
            t = max(t, int(wordDict[i].size()));
        }
        return func(0, s);
    }

};
