class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_size = len(nums)
        result = [1] * len(nums)
        prefix, suffix = 1, 1

        for i in range(nums_size):
            result[i] = prefix
            prefix *= nums[i]

        for i in range(nums_size - 1, -1, -1):
            result[i] *= suffix
            suffix *= nums[i]

        return result
