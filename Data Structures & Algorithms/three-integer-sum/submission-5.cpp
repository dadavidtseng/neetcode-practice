class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int numsSize = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end()); // sort the vector so we can know if it's duplicated
        unordered_map<int, int> freq;

        for (int i = 0; i < numsSize; ++i) {
            freq[nums[i]]++;
        }

        vector<vector<int>> result;

        for (int i = 0; i < numsSize; ++i) {
            freq[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < numsSize; ++j) {
                freq[nums[j]]--;
                if (j - 1 > i && nums[j] == nums[j - 1]) {
                    continue;
                }
                const int target = -(nums[i] + nums[j]);
                if (freq[target] > 0) {
                    result.push_back({nums[i], nums[j], target});
                }
            }

            for (int j = i + 1; j < numsSize; ++j) {
                freq[nums[j]]++;
            }
        }
        return result;
    }
};
