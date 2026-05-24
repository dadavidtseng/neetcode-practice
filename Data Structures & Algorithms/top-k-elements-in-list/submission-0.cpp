class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> container(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            container[nums[i]]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (unordered_map<int, int>::iterator it = container.begin(); it != container.end(); ++it)
        {
            buckets[it->second].push_back(it->first);
        }

        vector<int> result;

        for (int i = (int)buckets.size() - 1; i > 0; --i)
        {
            if (result.size() == k) break;
            for (int j = (int)buckets[i].size() - 1; j >= 0; --j)
            {
                // if (result.size() == k) break;
                result.push_back(buckets[i][j]);
            }
        }

        // for (int i = (int)buckets.size() - 1; i >= 0 && (int)result.size() < k; --i)
        // {
        //     for (int j = 0; j < (int)buckets[i].size() && (int)result.size() < k; ++j)
        //     {
        //         result.push_back(buckets[i][j]);
        //     }
        // }

        return result;
    }
};
