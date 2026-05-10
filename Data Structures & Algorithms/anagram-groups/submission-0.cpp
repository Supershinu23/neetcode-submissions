class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string t = strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(t);

        }
        vector<vector<string>> ans;
        for(auto it:m){
            ans.push_back(it.second);
        }

        // sort(ans.begin(), ans.end());
        return ans;
    }
};
