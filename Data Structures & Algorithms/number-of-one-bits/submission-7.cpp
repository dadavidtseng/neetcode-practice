class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int result = 0;

        // Iterate through all 32 bits in an integer
        for (int i = 0; i < 32; ++i) {
            // Increment the result if ith bit in an integer is 1
            if ((1 << i) & n) {
                result++;
            }
        }
        return result;
    }
};
