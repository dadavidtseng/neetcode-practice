class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // stores num(int), frequency(int)
        unordered_map<int, int> container(nums.size());

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            container[nums[i]]++;
        }

        // creates buckets
        vector<vector<int>> buckets(nums.size() + 1);

        // stores num in buckets based on frequency
        for (auto [num, frequency] : container) {
            buckets[frequency].push_back(num);
        }

        // creates result
        vector<int> result;

        for (int i = static_cast<int>(buckets.size()) - 1; i > 0; --i) {
            // result is full, break
            if (static_cast<int>(result.size()) == k) {
                break;
            }

            for (int j = static_cast<int>(buckets[i].size()) - 1; j >= 0; --j) {
                // result is full, break
                if (static_cast<int>(result.size()) == k) {
                    break;
                }

                result.push_back(buckets[i][j]);
            }
        }

        return result;
    }
};
