class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        current_combination = []

        self.backtrack(candidates, target, 0, current_combination, result)
        return result

    def backtrack(
        self,
        candidates: List[int],
        target: int,
        start_idx: int,
        current_combination: List[int],
        result: List[List[int]],
    ):
        # If remain_target is 0,
        # push the current_combination into result and return becuase we've got nothing to add to
        # current_combination
        if target == 0:
            result.append(current_combination.copy())
            return

        # If remain_target is less than current candidate,
        # return immediately because it's invalid
        if target < 0 or start_idx >= len(candidates):
            return

        # Push the current candidate into current_combination
        current_combination.append(candidates[start_idx])
        # Recursive call with new_remain_target and carry the current_combination
        self.backtrack(
            candidates, target - candidates[start_idx], start_idx, current_combination, result
        )
        # Remove this candidate from current_combination when unwinding from the recursive call
        current_combination.pop()
        self.backtrack(candidates, target, start_idx + 1, current_combination, result)
