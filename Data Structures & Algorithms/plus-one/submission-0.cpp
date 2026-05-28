class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1 ;
        int n = digits.size();
        int i = n-1;
        while(i>=0){
            int t = (digits[i]+rem)%10;
            rem = (digits[i]+rem)/10;
            digits[i] = t ;
            i--;
            if(rem == 0)break;
        }
        vector<int> ans ;
        if(rem!=0)ans.push_back(rem);
        for(int i=0;i<digits.size();i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }
};
