class Solution {
public:
    int helper(vector<int> &piles, int hour){
        int ans = 0 ;
        for(int i=0;i<piles.size();i++){
            ans += (piles[i] / hour);
            ans = piles[i]%hour==0 ? ans : ans+1;
        }
        return ans ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 ;
        int r = 0 ;
        for(int i=0;i<piles.size();i++){
            r = max(r, piles[i]);
        }

        while(r>l){
            int mid = (r+l)/2;

            if(helper(piles, mid)>h){
                l = mid+1;
            }else{
                r= mid;
            }
        }
        return l ;
    }
};
