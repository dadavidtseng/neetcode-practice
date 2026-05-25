class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int const numSize = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> valid;

        for (int i = 0; i < numSize; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = numSize - 1;

            while (left < right) {
                int const sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // found one! add it, then skip duplicates for both pointers
                    valid.push_back(nums[i]);
                    valid.push_back(nums[left]);
                    valid.push_back(nums[right]);
                    result.push_back(valid);
                    valid.clear();
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    // sum too small, move left pointer to right
                    left++;
                } else {
                    // sum too big, move right pointer to left
                    right--;
                }
            }
        }

        return result;
    }
};
