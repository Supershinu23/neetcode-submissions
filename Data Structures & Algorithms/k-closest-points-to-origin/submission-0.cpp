class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& vec, int k) {
        priority_queue<pair<double, vector<int>>> maxHeap;

        for(int i=0; i<vec.size();i++){
            double dist = sqrt(pow(vec[i][0], 2)+pow(vec[i][1], 2));
            maxHeap.push({dist, {vec[i][0], vec[i][1]}});

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans ;
        while(!maxHeap.empty()){
            pair<double, vector<int>> pq = maxHeap.top();
            maxHeap.pop();
            ans.push_back(pq.second);
        }
        return ans;
    }
};
