class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 ;
        int n = numbers.size();
        int r = n-1;
        vector<int> ans;
        while(r>l){
            if(numbers[l]+numbers[r]>target){
                r--;
            }else if(numbers[l]+numbers[r]<target){
                l++;
            }else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};
