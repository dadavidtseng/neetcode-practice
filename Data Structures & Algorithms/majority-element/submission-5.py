class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        result = 0
        freq = {}

        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        for num, f in freq.items():
            if f > len(nums) / 2:
                result = num
        return result

