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
        vector<int> start(n);
        vector<int> end(n);
        int startIdx = 0;
        int endIdx = 0;

        for (int i = 0; i < n; ++i) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        while (startIdx < n) {
            if (start[startIdx] < end[endIdx]) {
                result++;
                startIdx++;
            } else if (start[startIdx] >= end[endIdx]) {
                result--;
                endIdx++;
            }

            maxResult = max(maxResult, result);
        }

        return maxResult;
    }
};
