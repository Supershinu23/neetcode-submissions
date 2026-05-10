class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m ;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> ans ;
        priority_queue<pair<int, int>> pq;

        for(auto it:m){
            pq.push({it.second, it.first});
        }

        while(k){
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }
        return ans ;
    }
};
