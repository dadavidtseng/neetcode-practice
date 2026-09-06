class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(s)
        n = len(t)
        dp = [0] * n

        for i in range(m):
            for j in range(n - 1, -1, -1):
                if s[i] == t[j]:
                    if j == 0:
                        dp[0] += 1
                    else:
                        dp[j] += dp[j - 1]
        return dp[-1]
