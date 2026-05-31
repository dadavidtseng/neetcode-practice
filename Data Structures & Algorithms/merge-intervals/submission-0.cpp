class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);

        for (int i = 1; i < (int)intervals.size(); i++) {
            vector<int>& interval = intervals[i];

            if (interval[0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                result.push_back(interval);
            }
        }

        return result;
    }
};
