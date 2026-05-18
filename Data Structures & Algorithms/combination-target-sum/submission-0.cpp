class Solution {
public:
    void func(vector<int> &nums, int ind, int target, vector<int> &temp, vector<vector<int>> &ans){
    if(ind<0){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }

    func(nums, ind-1, target, temp, ans);
    if(target-nums[ind]>=0){
        temp.push_back(nums[ind]);
        func(nums, ind, target-nums[ind], temp, ans);
        temp.pop_back();
    }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(nums, nums.size()-1, target, temp, ans);
        return ans;
    }
};
