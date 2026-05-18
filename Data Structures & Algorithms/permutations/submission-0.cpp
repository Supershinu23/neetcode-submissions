class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> &nums, vector<bool>&picks, vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        

        for(int i=0;i<nums.size();i++){
            if(!picks[i]){
                picks[i] = true;
                temp.push_back(nums[i]);
                func(nums, picks, temp);
                temp.pop_back();
                picks[i] = false;
            }
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> picks(n, false);
        vector<int> temp;
        func(nums, picks, temp);
        return ans;
    }
};
