class Solution {
   public:
    int findMin(vector<int>& nums) {
        int const numSize = static_cast<int>(nums.size());

        if (numSize == 1) {
            return nums[0];
        }

        int l = 0;
        int r = numSize - 1;
        int m = (l + r) / 2;

        while (l + 1 != r) {
            if (nums[m] < nums[r]) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m;
                m = (l + r) / 2;
            }
        }

        return min(nums[l], nums[r]);
    }
};
