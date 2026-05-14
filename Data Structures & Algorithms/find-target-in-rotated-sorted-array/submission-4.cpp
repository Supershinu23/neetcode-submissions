class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 ;
        int r = n-1;
        while(r>l){
            int mid = (r+l)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]<nums[r]){
                if(target> nums[mid] && target<=nums[r]){
                    l = mid+1;
                }else{
                    r = mid;
                }
            }else{
                {
                if(nums[mid] > target && target >= nums[l]){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            }
        }
        cout<<l;
        if(nums[l] == target)return l;
        return -1;
    }
};
