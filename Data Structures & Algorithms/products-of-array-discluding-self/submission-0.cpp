class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        vector<int> prefixResult;
        vector<int> suffixResult;
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < nums.size(); ++i) {
            prefixResult.push_back(prefix);
            prefix *= nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            suffixResult.push_back(suffix);
            suffix *= nums[i];
        }

        std::reverse(suffixResult.begin(), suffixResult.end());
        result.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(prefixResult[i] * suffixResult[i]);
        }

        return result;
    }
};
