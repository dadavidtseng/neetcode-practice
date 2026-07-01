class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        self.backtrack(s, 0, [], result)
        return result

    def backtrack(self, s: str, idx: int, curr: List[str], result: List[List[str]]):
        if idx == len(s):
            result.append(curr.copy())
            return

        for i in range(idx, len(s)):
            sub = s[idx : i + 1]
            if sub == sub[::-1]:
                curr.append(sub)
                self.backtrack(s, i + 1, curr, result)
                curr.pop()
