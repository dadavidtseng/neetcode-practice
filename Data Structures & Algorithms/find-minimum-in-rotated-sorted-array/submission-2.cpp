class Solution {
   public:
    int findMin(vector<int>& nums) {
        int const numSize = static_cast<int>(nums.size());
        int l = 0;
        int r = numSize - 1;
        int m = (l + r) / 2;

        while (l < r) {
            if (nums[m] < nums[r]) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m + 1;
                m = (l + r) / 2;
            }
        }

        return nums[l];
    }
};
