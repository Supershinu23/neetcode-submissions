class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        int n = temp.size();
        vector<int> ans ;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temp[s.top()]<=temp[i])s.pop();
            if(!s.empty())ans.push_back(s.top()-i);
            else ans.push_back(0);

            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
};
