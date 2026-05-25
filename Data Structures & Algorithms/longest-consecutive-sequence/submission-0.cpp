class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set const numSet(nums.begin(), nums.end());
        int longestLength = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int length = 0;

            if (!numSet.contains(nums[i] - 1)) {
                while (numSet.contains(nums[i] + length)) {
                    length++;
                }
            }

            longestLength = std::max(length, longestLength);
        }

        return longestLength;
    }
};
