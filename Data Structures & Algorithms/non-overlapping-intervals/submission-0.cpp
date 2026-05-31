class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        std::sort(intervals.begin(), intervals.end(),
                  [](vector<int> const& a, vector<int> const& b) { return a[1] < b[1]; });

        int result = 0;
        int tracked = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < tracked) {
                result++;
            } else {
                tracked = intervals[i][1];
            }
        }

        return result;
    }
};
