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
        // Sort intervals in ascending order using interval.start
        sort(intervals.begin(), intervals.end(),
             [](Interval& x, Interval& y) { return x.start < y.start; });

        // Iterate through intervals
        // Return false if adjancent intervals overlap
        // Note that we don't need to check anything besides the adjancent interval because if
        // intervals[i - 2] overlaps with intervals[i], it's definitely overlapping with
        // intervals[i - 1] as well
        for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};
