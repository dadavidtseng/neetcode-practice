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
        int size = static_cast<int>(intervals.size());

        for (int i = 0; i < size; i++) {
            Interval& x = intervals[i];
            for (int j = i + 1; j < size; j++) {
                Interval& y = intervals[j];
                {
                    // Return false if x and y overlap
                    // min(x.end, y.end) -> leftmost of right edges
                    // max(x.start, y.start) -> rightmost of left edges
                    if (min(x.end, y.end) > max(x.start, y.start)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
