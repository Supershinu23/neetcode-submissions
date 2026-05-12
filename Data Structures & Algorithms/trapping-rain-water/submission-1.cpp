class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int ans = 0;
        while (l < r) {
           leftMax = max(leftMax, height[l]);
           rightMax = max(rightMax, height[r]);
           if(height[l] > height[r]){
            ans+=min(leftMax, rightMax)-height[r];
            r--;
           }else{
            ans+=min(leftMax, rightMax) - height[l];l++;
           }
        }
        return ans;
    }
};