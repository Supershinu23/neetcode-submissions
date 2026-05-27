class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> temp ;
        sort(intervals.begin(), intervals.end());
        temp.push_back(intervals[0]);
        int ans = 0 ;
        for(int i=1;i<intervals.size();i++){
            if(temp.back()[1]>intervals[i][0]){
                temp.back()[1] = min(temp.back()[1], intervals[i][1]);
                ans++;
            }else{
                temp.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
