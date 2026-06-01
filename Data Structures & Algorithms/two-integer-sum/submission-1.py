class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_size = len(nums)

        # Iterate through every possible pairs in nums
        for i in range(nums_size):
            for j in range(i + 1, nums_size):
                # return result if we've found target
                if nums[i] + nums[j] == target:
                    return [i, j]

        return []
