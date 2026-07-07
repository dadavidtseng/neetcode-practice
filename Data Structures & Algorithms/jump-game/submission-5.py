class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_idx = 0

        # Return false if current idex is greater than the max index we can reach as we iterating
        # through nums;
        # max(maxIdx, i + nums[i]) allows us to keep track of the maximum index we can reach
        for i in range(len(nums)):
            if i > max_idx:
                return False
            max_idx = max(max_idx, i + nums[i])
        # Returns true after successfully iterating through nums
        return True
