class Solution {
public:
    int func(int ind, vector<int> &nums){
        if(ind==0)return nums[ind] ;
        return max(nums[ind], nums[ind]*func(ind-1, nums));
    }
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currmin = 1, currmax = 1;
        for(int num: nums){
            int temp = num*currmax;
            currmax = max(max(num, temp), num*currmin);
            currmin = min(min(num, temp), num*currmin);
            res= max(res, currmax);
        }
        return res;
    }
};
