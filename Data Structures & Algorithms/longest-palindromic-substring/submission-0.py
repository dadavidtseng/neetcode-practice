class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = (0, 0, 0)
        result_length = 0
        s_size = len(s)

        def expand(L: int, R: int) -> tuple[int, int, int]:
            while L >= 0 and R < s_size and s[L] == s[R]:
                L -= 1
                R += 1
            return (R - L + 1, L, R)

        for idx in range(s_size):
            odd = expand(idx, idx)
            even = expand(idx, idx + 1)
            candidate = (0, 0, 0)
            if odd[0] > even[0]:
                candidate = odd
            else:
                candidate = even

            if candidate[0] > result_length:
                result_length = candidate[0]
                result = candidate

        return s[result[1] + 1 : result[2]]
