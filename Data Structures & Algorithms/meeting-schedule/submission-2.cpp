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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        for (int i = 0; i < (int)intervals.size(); i++) {
            Interval& a = intervals[i];
            for (int j = i + 1; j < (int)intervals.size(); j++) {
                Interval& b = intervals[j];
                {
                    // min(a.end, b.end) -> leftmost of right edges
                    // max(a.start, b.start) -> rightmost of left edges
                    if(min(a.end, b.end) > max(a.start, b.start))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
