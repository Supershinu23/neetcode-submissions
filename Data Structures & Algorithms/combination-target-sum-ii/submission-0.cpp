class Solution {
public:
    void func(vector<int> &candidates, int ind, int target, vector<int> &temp, vector<vector<int>> &ans){
        if(ind<0){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target>=candidates[ind]){
            temp.push_back(candidates[ind]);
            func(candidates, ind-1, target-candidates[ind], temp, ans);
            temp.pop_back();
        }
        while (ind - 1 >= 0 && candidates[ind] == candidates[ind - 1]) {
            ind--;
        }
        func(candidates, ind-1, target, temp, ans);
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        func(candidates, candidates.size()-1, target, temp, ans);
        return ans;
    }
};
