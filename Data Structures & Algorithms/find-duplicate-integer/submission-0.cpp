class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i= 0 ;
        int n = nums.size();
        while(i<n){
            if(i+1 == nums[i]){
                i++;
            }else{
                if(nums[nums[i]-1]==nums[i]){
                    return nums[i];
                }else{
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
        }
        return 0;
    }
};
