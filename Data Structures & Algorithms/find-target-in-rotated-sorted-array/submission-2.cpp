class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int const numSize = static_cast<int>(nums.size());
        int l = 0;
        int r = numSize - 1;
        int m = (l + r) / 2;

        while (l <= r) {
            // if index m happens to be the target
            if (nums[m] == target) {
                return m;
            }

            // if the value of index m is greater than the value of index r
            // this means the array has been rotated and l and m are on the left sequence
            if (nums[m] > nums[r]) {
                // nums[l] <= target < nums[m]
                // target is in the rotated left sequence
                // move r pointer towards m pointer
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                    m = (l + r) / 2;
                }
                // target is in the sorted right sequence
                // move l pointer towards m pointer
                else {
                    l = m + 1;
                    m = (l + r) / 2;
                }
            }
            // the right half is sorted
            else {
                // nums[m] <= target < nums[r]
                // target is in the sorted right sequence
                // move l pointer towards m pointer
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                    m = (l + r) / 2;
                }
                // target is in the sorted left sequence
                // move r pointer towards m pointer
                else {
                    r = m - 1;  // target must be in the left half
                    m = (l + r) / 2;
                }
            }
        }

        // return -1 if nothing has been found
        return -1;
    }
};
