class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create the frequency map
        unordered_map<int, int> m(nums.size());

        // Iterate through nums and increment the frequency for nums[i]
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            m[nums[i]]++;
        }

        vector<pair<int, int>> v;
        v.reserve(m.size());

        // Iterate through the frequency map in order to turn an unordered_map into vector
        for (auto const& [num, freq] : m)
        {
            v.emplace_back(freq, num);
        }
        
         sort(v.rbegin(), v.rend());

        vector<int> result;
        result.reserve(k);
        
        // Iterate through k elements and push num into result
        for (int i = 0; i < k; ++i)
        {
            result.push_back(v[i].second);
        }

        return result;
    }
};
