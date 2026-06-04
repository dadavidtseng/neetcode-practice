class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> numIndexMap;
        vector<int> result;

        // Iterate through every element to find target
        // Build numIndexMap along the way
        for (int i = 1; i < static_cast<int>(numbers.size() + 1); ++i) {
            int const diff = target - numbers[i - 1];

            if (numIndexMap.contains(diff)) {
                result = {numIndexMap[diff], i};

                return result;
            }

            numIndexMap[numbers[i - 1]] = i;
        }

        // return empty result to satisfy compiler
        // Since the problem says there is guaranteed to be exactly one solution,
        // so we will never return an empty array.
        return result;
    }
};
