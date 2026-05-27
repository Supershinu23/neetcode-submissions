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
struct compare{
        bool operator()(Interval a, Interval b){
            if(a.start==b.start)return b.end < a.end;
            return a.start < b.start;
        }
    };
class Solution {
    
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare());
        int end = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start < end)return false;
            end = intervals[i].end;
        }
        return true;
    }
};
