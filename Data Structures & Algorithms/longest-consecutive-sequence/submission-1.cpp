class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s ;
        int n = nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(auto it: s){
            int j =1 ;
            while(s.find(it-j)!=s.end())j++;
            ans = max(ans, j);
        }
        return ans;
    }
};
