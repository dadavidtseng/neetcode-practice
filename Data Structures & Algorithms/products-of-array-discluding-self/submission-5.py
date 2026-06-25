class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nums_size = len(nums)
        result = [0] * nums_size
        prefix = [0] * nums_size
        suffix = [0] * nums_size

        prefix[0] = 1
        suffix[nums_size-1] = 1

        for i in range(1,nums_size):
            prefix[i] = nums[i-1]*prefix[i-1]

        for i in range(nums_size - 2, -1, -1):
            suffix[i] = nums[i + 1] * suffix[i + 1]
        for i in range(nums_size):
            result[i] = prefix[i] * suffix[i]

        return result