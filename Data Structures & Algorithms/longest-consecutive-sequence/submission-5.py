class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:    
            return 0

        nums.sort()
        result = 1
        streak = 1

        for idx in range(len(nums) - 1):
            if nums[idx] + 1 == nums[idx + 1]:
                streak += 1
                result = max(result, streak)
            elif nums[idx] == nums[idx + 1]:
                continue
            else:
                streak = 1

        return result