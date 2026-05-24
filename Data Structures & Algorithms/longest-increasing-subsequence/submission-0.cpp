class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans ;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(ans.back()>=nums[i]){
                int t = lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();        
                ans[t] = nums[i];
            }else{
                ans.push_back(nums[i]);
            }
        }
        return ans.size();

    }
};
