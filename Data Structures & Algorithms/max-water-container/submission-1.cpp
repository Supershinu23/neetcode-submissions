class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int ans = 0 ;
        while(l<r){
            int maxWater = (r-l)* min(heights[l], heights[r]);
            if(heights[l]==heights[r]){
                l++;
                r--;
            }else if(heights[l]>heights[r]){
                r--;
            }else{
                l++;
            }
            ans = max(ans, maxWater);
        }
        return ans;

    }
};
