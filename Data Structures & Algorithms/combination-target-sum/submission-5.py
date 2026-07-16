class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        curr = []

        def backtrack(target: int, idx: int):
            # If target is 0,
            # store curr into result and return because we've got nothing to add to curr
            if target == 0:
                result.append(curr.copy())
                return

            # If target or idx is invalid
            # return immediately because won't be able to find anything going further
            if target < 0 or idx >= len(nums):
                return

            # Push the current candidate into curr
            curr.append(nums[idx])
            # Recursive call with new remaining target
            backtrack(target - nums[idx], idx)
            # Remove candidates[idx] from curr when unwinding from the recursive call
            curr.pop()
            # Recursive call with target
            backtrack(target, idx + 1)

        backtrack(target, 0)
        return result
