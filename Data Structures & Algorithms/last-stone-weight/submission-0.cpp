class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int i=0; i<stones.size();i++){
            maxHeap.push(stones[i]);
        }
        while(!maxHeap.empty()){
            if(maxHeap.size()==1)return maxHeap.top();
            int one = maxHeap.top();maxHeap.pop();
            int two = maxHeap.top();maxHeap.pop();
            if(one!=two){
                maxHeap.push(abs(one-two));
            }
        }
        return 0;
    }
};
