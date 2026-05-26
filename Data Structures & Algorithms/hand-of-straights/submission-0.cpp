class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        int n = hand.size();

        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int curr = hand[i];
                vis[i] = 1;
                int currCount = 1;
                int j = i+1;
                while(currCount<groupSize && j< n){
                    if(vis[j]==1 || curr==hand[j]){
                        j++;
                        continue;
                    }
                    if(curr+1 != hand[j])return false;
                    curr = hand[j] ;
                    vis[j] = 1 ;
                    j++;
                    currCount++;
                }
                if(currCount!=groupSize)return false;
            }
        }
        return true;
    }
};
