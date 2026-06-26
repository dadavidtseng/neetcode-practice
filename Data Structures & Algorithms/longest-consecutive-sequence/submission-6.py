class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        result = 0
        store = set(nums)

        for s in store:
            if (s - 1) not in store:
                streak = 1
                while s + streak in store:
                    streak += 1
                result = max(result, streak)
        return result
