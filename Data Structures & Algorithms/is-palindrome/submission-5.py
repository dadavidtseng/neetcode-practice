class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1

        while l < r:
            while l < r and not self.alphaNum(s[l]):
                l += 1

            while l < r and not self.alphaNum(s[r]):
                r -= 1

            if s[l].lower() != s[r].lower():
                return False

            l += 1
            r -= 1

        return True

    def alphaNum(self, c):
        x = ord(c)

        return ord("A") <= x <= ord("Z") or ord("a") <= x <= ord("z") or ord("0") <= x <= ord("9")
