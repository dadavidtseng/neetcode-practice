"""
Understand:
Provided an integer array, which is inordered, elements can be duplicated
Return the longest length of increasing/decreasing subarray
Ex1:
nums = [1,4,3,3,2]
increasing subarray is [1], [1, 4], [4], [3], [3], [2]
decreasing subarray is [1], [4], [4, 3], [3], [3], [3, 2], [2]

Match:
Array, Stack?

Plan:
Iterate through the integer array forward and backward and record the max length of subarray
As we iterate, we hold the target subarray if it matches the condition of increasing/decreasing
"""


class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        result = 1
        inc = 1
        dec = 1

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                inc += 1
                dec = 1
            elif nums[i] < nums[i - 1]:
                dec += 1
                inc = 1
            else:
                inc = 1
                dec = 1
            result = max(result, inc, dec)

        return result
