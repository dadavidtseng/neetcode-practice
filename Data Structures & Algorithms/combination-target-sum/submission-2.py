class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        current_combination = []

        # Sort the candidates before entering the recursive call for early termination
        candidates.sort()
        self.backtrack(candidates, target, 0, current_combination, result)
        return result

    def backtrack(
        self,
        candidates: List[int],
        remain_target: int,
        start_idx: int,
        current_combination: List[int],
        result: List[List[int]],
    ):
        # If remain_target is 0,
        # push the current_combination into result and return becuase we've got nothing to add to
        # current_combination
        if remain_target == 0:
            result.append(current_combination.copy())
            return

        # Iterate candidates from start_idx
        for i in range(start_idx, len(candidates)):
            new_remain_target = remain_target - candidates[i]

            # If remain_target is less than current candidate,
            # return immediately because it's invalid
            if new_remain_target < 0:
                return

            # Push the current candidate into current_combination
            current_combination.append(candidates[i])
            # Recursive call with new_remain_target and carry the current_combination
            self.backtrack(candidates, new_remain_target, i, current_combination, result)
            # Remove this candidate from current_combination when unwinding from the recursive call
            current_combination.pop()
