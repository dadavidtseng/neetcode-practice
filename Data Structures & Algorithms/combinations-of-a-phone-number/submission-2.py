class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = []
        if digits == "":
            return result

        result = []

        digit_to_alph = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"],
        }
        self.backtrack(digits, 0, "", digit_to_alph, result)
        return result

    def backtrack(self, digits: str, idx: int, curr: str, digit_to_alpha: dict, result: List[str]):
        if len(curr) == len(digits):
            result.append(curr)
            return

        for v in digit_to_alpha[digits[idx]]:
            self.backtrack(digits, idx + 1, curr + v, digit_to_alpha, result)
