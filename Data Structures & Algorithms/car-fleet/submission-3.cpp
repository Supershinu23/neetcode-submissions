class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec;
        for(int i=0;i<position.size();i++){
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.begin(), vec.end());

        stack<double> st;
        for(int i = vec.size()-1; i>=0;i--){
            double time = (double)(target - vec[i].first)/vec[i].second;
            // time = (target - vec[i].first)%vec[i].second == 0 ? time : time+1;

            if(st.empty() || time>st.top())st.push(time);
        }
        return st.size();
    }
};
