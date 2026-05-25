class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int const size = static_cast<int>(nums.size());
        vector<int> result;
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < size; ++i) {
            result.push_back(prefix);
            prefix *= nums[i];
        }

        for (int i = size - 1; i >= 0; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};
