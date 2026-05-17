class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> maxHeap;
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        int ans  = 0 ;
        // while(!maxHeap.empty()){
        //     ans = maxHeap.top();
        //     maxHeap.pop();
        //     cout<<ans<<" ";
        // }
        return maxHeap.top();
    }
};
