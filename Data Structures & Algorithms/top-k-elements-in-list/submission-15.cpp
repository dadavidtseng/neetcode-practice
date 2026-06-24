class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create the frequency map
        unordered_map<int, int> m(nums.size());

        // Iterate through nums and increment the frequency for nums[i]
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            m[nums[i]]++;
        }

        // Create buckets
        // Note that we're using nums.size() + 1 because we want 0 to nums.size()
        vector<vector<int>> buckets(nums.size() + 1);

        // Store num in buckets based on frequency
        for (auto const& [num, freq] : m) {
            buckets[freq].push_back(num);
        }

        vector<int> result;

        // Iterate through buckets and push every num in each bucket to result
        for (int i = static_cast<int>(buckets.size()) - 1; i >= 0; --i) {
            for (int j = 0; j < static_cast<int>(buckets[i].size()); ++j) {
                result.push_back(buckets[i][j]);

                // Return result if result.size() equals to k
                if (static_cast<int>(result.size()) == k) {
                    return result;
                }
            }
        }

        // This will never be reached since
        // k is in the range [1, the number of unique elements in the array].
        return result;
    }
};
