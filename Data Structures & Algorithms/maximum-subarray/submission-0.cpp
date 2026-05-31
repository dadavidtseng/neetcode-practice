class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            curSum = max(curSum, 0);
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
