class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set const numSet(nums.begin(), nums.end());
        int longestLength = 0;

        for (int num : numSet) {
            int length = 0;

            if (!numSet.contains(num - 1)) {
                while (numSet.contains(num + length)) {
                    length++;
                }
            }

            longestLength = std::max(length, longestLength);
        }

        return longestLength;
    }
};
