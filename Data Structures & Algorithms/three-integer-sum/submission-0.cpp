class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n =nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i-1>=0 && nums[i-1]==nums[i])continue;
            int l = i+1;
            int r = n-1;
            while(l<r){
                if(nums[l] + nums[r] +nums[i] == 0){
                    vector<int> temp ;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    while(l+1< n && nums[l+1]==nums[l])l++;
                    while(r-1>=0&& nums[r-1]==nums[r])r--;
                    l++;
                    r--;
                }else if(nums[l] + nums[r] + nums[i] > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans ;
    }
};
