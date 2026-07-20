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
        result = 0
        sub = []

        for i in range(len(nums)):
            if not sub or sub[-1] < nums[i]:
                sub.append(nums[i])
                result = max(result, len(sub))
            elif sub[-1] >= nums[i]:
                result = max(result, len(sub))
                sub.clear()
                sub.append(nums[i])
            # print(f"result= {result}, sub= {sub}")
        
        sub.clear()

        for i in range(len(nums)):
            if not sub or sub[-1] > nums[i]:
                sub.append(nums[i])
                result = max(result, len(sub))
            elif sub[-1] <= nums[i]:
                result = max(result, len(sub))
                sub.clear()
                sub.append(nums[i])
            print(f"result= {result}, sub= {sub}")
        return result
