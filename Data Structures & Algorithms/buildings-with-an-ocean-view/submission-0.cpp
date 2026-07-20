class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> s ;
        int n = heights.size();
        vector<int> ans ;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<heights[i])s.pop();

            if(s.empty())ans.push_back(i);
            s.push(heights[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};