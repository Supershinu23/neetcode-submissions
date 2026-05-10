class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n) , rightSmaller(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            if(!s.empty())leftSmaller[i] = s.top();
            else leftSmaller[i] =  -1;

            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            if(!s.empty())rightSmaller[i] = s.top();
            else rightSmaller[i] = n;

            s.push(i);
        }

        int ans  = 0;
        for(int i=0;i<n;i++){
            cout<<"for index i "<<i<<" leftSmaller: "<<leftSmaller[i]<<" and rightSmaller: "<<rightSmaller[i]<<" |"; 
            int area = (rightSmaller[i]-leftSmaller[i]-1)*heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};
