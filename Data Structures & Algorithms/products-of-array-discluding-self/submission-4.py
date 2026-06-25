class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        zero_count = 0
        result = [0] * len(nums)

        for num in nums:
            if num == 0:
                zero_count += 1
            else:
                product *= num

        if zero_count > 1:
            return result

        for i, c in enumerate(nums):
            if zero_count == 0:
                result[i] = product // c
            else:
                if c == 0:
                    result[i] = product

        return result
