class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        // x ^ x = 0
        // x ^ 0 = x

        size_t n = nums.size();  // [0,n] range
        int result = n;          // this gets the n since we only have 0 to n-1
        for (size_t i = 0; i < n; i++) {
            result ^= i ^ nums[i];
        }

        return result;
    }
};
