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
        int result = 0;
        int maxResult = 0;

        int const n = static_cast<int>(intervals.size());
        map<int, int> events;

        for (int i = 0; i < n; ++i) {
            events[intervals[i].start]++;
            events[intervals[i].end]--;
        }

        for (map<int, int>::iterator it = events.begin(); it != events.end(); ++it) {
            result += it->second;
            maxResult = max(maxResult, result);
        }

        return maxResult;
    }
};
