class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0 ;
        int r = nums.size()-1;
        while(r>l){
            int mid = (r+l)/2;
            if(nums[mid] < nums[r]){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return nums[l];
    }
};
