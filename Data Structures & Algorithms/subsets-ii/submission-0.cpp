class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> &nums, int ind, vector<int>&temp){
        if(ind<0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(nums, ind-1, temp);
        temp.pop_back();

        while(ind-1>=0 && nums[ind]==nums[ind-1]){
            ind--;
        }
        func(nums, ind-1, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        func(nums, nums.size()-1, temp);
        return ans;
    }
};
