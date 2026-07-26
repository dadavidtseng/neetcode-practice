class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int const numSize = static_cast<int>(nums.size());
        int L = 0;
        int R = numSize - 1;

        while (L <= R) {
            int M = L + (R - L) / 2;

            // Return M if we find our target
            if (nums[M] == target) {
                return M;
            }

            // if the value of index m is greater than the value of index r
            // this means the array has been rotated and l and m are on the left sequence
            else if (nums[M] > nums[R]) {
                // nums[l] <= target < nums[m]
                // target is in the rotated left sequence
                // move r pointer towards m pointer
                if (target >= nums[L] && target < nums[M]) {
                    R = M - 1;
                }
                // target is in the sorted right sequence
                // move l pointer towards m pointer
                else {
                    L = M + 1;
                }
            }
            // the right half is sorted
            else {
                // nums[m] <= target < nums[r]
                // target is in the sorted right sequence
                // move l pointer towards m pointer
                if (target > nums[M] && target <= nums[R]) {
                    L = M + 1;
                }
                // target is in the sorted left sequence
                // move r pointer towards m pointer
                else {
                    R = M - 1;  // target must be in the left half
                }
            }
        }
        // Return -1 if we couldn't find target
        return -1;
    }
};
