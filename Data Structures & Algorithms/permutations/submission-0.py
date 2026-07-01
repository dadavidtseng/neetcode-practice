class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.backtrack(nums, [], set(), result)
        return result

    def backtrack(self, nums: List[int], curr: List[int], used: set[int], result: List[List[int]]):
        if len(curr) == len(nums):
            result.append(curr.copy())
            return

        for i in range(len(nums)):
            if i in used:
                continue
            used.add(i)
            curr.append(nums[i])
            self.backtrack(nums, curr, used, result)
            curr.pop()
            used.remove(i)
