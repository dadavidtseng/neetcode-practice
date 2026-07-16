class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        curr = []

        # Sort the candidates before entering the recursive call for early termination
        nums.sort()

        def backtrack(target: int, idx: int):
            # If target is 0,
            # store curr into result and return because we've got nothing to add to curr
            if target == 0:
                result.append(curr.copy())
                return

            # Iterate candidates from idx
            for i in range(idx, len(nums)):
                # If the current candidate is invalid
                # return immediately because won't be able to find anything going further
                if nums[i] > target:
                    return

                # Push the current candidate into curr
                curr.append(nums[i])
                # Recursive call with new remaining target
                backtrack(target - nums[i], i)
                # Remove this candidate from curr when unwinding from the recursive call
                curr.pop()

        backtrack(target, 0)
        return result