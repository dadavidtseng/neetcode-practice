class Solution {
   public:
    int findMin(vector<int>& nums) {
        const int numSize = static_cast<int>(nums.size());
        int L = 0;
        int R = numSize - 1;

        int result = nums[0];

        while (L <= R) {
            if (nums[L] < nums[R]) {
                result = min(result, nums[L]);
                break;
            }
            int M = (L + R) / 2;
            result = min(result, nums[M]);

            if (nums[M] >= nums[L]) {
                L = M + 1;
            } else {
                R = M - 1;
            }
        }

        return result;
    }
};
