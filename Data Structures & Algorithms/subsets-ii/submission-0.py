class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        current_combination = []
        nums.sort()
        self.backtrack(nums, 0, current_combination, result)
        return result

    def backtrack(
        self, nums: List[int], idx: int, current_combination: List[int], result: List[List[int]]
    ):
        result.append(current_combination.copy())

        for i in range(idx, len(nums)):
            if i > idx and nums[i] == nums[i - 1]:
                continue
            current_combination.append(nums[i])
            self.backtrack(nums, i + 1, current_combination, result)
            current_combination.pop()
