class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), post(n);
        int curr = 1 ;
        for(int i=0;i<n;i++){
            pre[i] = curr;
            curr = curr*nums[i] ;
        }
        curr = 1;
        for(int i=n-1;i>=0;i--){
            post[i] = curr ;
            curr*= nums[i];
        }

        vector<int> ans(n) ;
        for(int i=0;i<n;i++){
            ans[i] = pre[i] * post[i];
        }
        return ans;

    }
};
