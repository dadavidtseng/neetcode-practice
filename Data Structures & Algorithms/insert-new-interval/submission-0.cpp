class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool hasInserted = false;

        for (int i = 0; i < (int)intervals.size(); i++) {
            vector<int>& interval = intervals[i];

            // min(a.end, b.end) -> leftmost of right edges
            // max(a.start, b.start) -> rightmost of left edges
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            } else if (min(newInterval[1], interval[1]) >= max(newInterval[0], interval[0])) {
                int newStart = min(newInterval[0], interval[0]);
                int newEnd = max(newInterval[1], interval[1]);

                newInterval = {newStart, newEnd};
            } else if (interval[0] > newInterval[1]) {
                if (!hasInserted) {
                    result.push_back(newInterval);
                    hasInserted = true;
                }

                result.push_back(interval);
            }
        }
if (!hasInserted)
        {
            result.push_back(newInterval);
        }
        return result;
    }
};
