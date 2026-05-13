class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        int n = nums.size();
        vector<int> ans ;
        for(int i=0;i<n;i++){

            while(!dq.empty() && dq.back().first<nums[i])dq.pop_back();
            while(!dq.empty() && dq.front().second < i-k+1)dq.pop_front();
            dq.push_back({nums[i], i});
            if(i-k+1>=0)ans.push_back(dq.front().first);
        }
        return ans;
    }
};
