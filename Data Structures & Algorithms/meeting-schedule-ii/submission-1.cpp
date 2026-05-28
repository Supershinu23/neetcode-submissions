/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int ans = 0;
        vector<int> startV ;
        vector<int> endV;
        for(int i=0;i<intervals.size();i++){
            startV.push_back(intervals[i].start);
            endV.push_back(intervals[i].end);
        }
        sort(startV.begin(), startV.end());
        sort(endV.begin(), endV.end());
        int p1 = 0, p2 = 0, curr = 0 ;
        int n = intervals.size();
        while(p1< n && p2 <n){
            if(startV[p1]<endV[p2]){
                curr++;
                p1++;
            }else{
                curr--;
                p2++;
            }
            ans = max(ans, curr);
        }

        return ans;
    }
};
