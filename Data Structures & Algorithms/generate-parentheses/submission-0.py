class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.backtrack(n, "", 0, 0, result)
        return result

    def backtrack(self, n, curr: str, open, close, result: List[str]):
        if len(curr) == 2 * n:
            result.append(curr)
            return

        if open < n:
            self.backtrack(n, curr + "(", open + 1, close, result)

        if open > close:
            self.backtrack(n, curr + ")", open, close + 1, result)
