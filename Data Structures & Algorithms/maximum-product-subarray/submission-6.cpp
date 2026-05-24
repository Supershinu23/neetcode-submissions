class Solution {
public:
    
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
