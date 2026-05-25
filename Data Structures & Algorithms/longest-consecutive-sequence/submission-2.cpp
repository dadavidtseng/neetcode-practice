class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set const numSet(nums.begin(), nums.end());
        int longestLength = 0;

        for (int const num : numSet) {
            if (!numSet.contains(num - 1)) {
                int length = 0;

                while (numSet.contains(num + length)) {
                    length++;
                }

                longestLength = std::max(length, longestLength);
            }
        }

        return longestLength;
    }
};
