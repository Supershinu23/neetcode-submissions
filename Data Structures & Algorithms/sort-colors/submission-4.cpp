class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int r = n-1;
        
        int t = l;
        while(t>=l && t<=r){
            if(nums[t]==0){
                swap(nums[l], nums[t]);
                l++;
                t++;
            }
            else if(nums[t]==2){
                swap(nums[r], nums[t]);
                r--;
            }else{
                t++;
        }
        }
    }
};