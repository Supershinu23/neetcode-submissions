class Solution {
public:
    void func(vector<int>& nums, int ind, vector<int> &temp, vector<vector<int>> &ans){
        if(ind<0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(nums, ind-1, temp, ans);
        temp.pop_back();
        func(nums, ind-1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp ;
        vector<vector<int>> ans ;
        int n = nums.size();
        func(nums, n-1, temp, ans);
        return ans;
    }
};
