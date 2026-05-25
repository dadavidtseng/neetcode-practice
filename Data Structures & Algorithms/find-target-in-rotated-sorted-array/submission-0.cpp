class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int const numSize = static_cast<int>(nums.size());
        int l = 0;
        int r = numSize - 1;
        int m = (l + r) / 2;

        while (l < r) {
            if (nums[m] == target) {
                return m;
            }

            if (nums[m] > nums[r]) {
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                    m = (l + r) / 2;

                } else {
                    l = m + 1;
                    m = (l + r) / 2;
                }
            } else {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;  // target is in the sorted right half
                    m = (l + r) / 2;
                } else {
                    r = m - 1;  // target must be in the left half
                    m = (l + r) / 2;
                }
            }
        }

        if (nums[l] != target) {
            return -1;
        }

        return l;
    }
};
