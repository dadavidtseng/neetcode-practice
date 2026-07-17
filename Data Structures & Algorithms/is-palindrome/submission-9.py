class Solution:
    def isPalindrome(self, s: str) -> bool:
        L = 0
        R = len(s) - 1

        # Return true is the character is a letter or a digit
        def is_alpha_num(c: str) -> bool:
            return (
                ord("A") <= ord(c) <= ord("Z")
                or ord("a") <= ord(c) <= ord("z")
                or ord("0") <= ord(c) <= ord("9")
            )

        # Exit the while loop when L/R pointers cross
        # 1. Advance L pointer when L/R pointers don't cross and s[L] is not alphanumeric
        # 2. Decrement R pointer when L/R pointers don't cross and s[R] is not alphanumeric
        # 3. Return false if lowercased s[L] and s[R] are not equal
        # 4. Move L/R pointers toward the center
        while L < R:
            while L < R and not is_alpha_num(s[L]):
                L += 1
            while L < R and not is_alpha_num(s[R]):
                R -= 1
            if s[L].lower() != s[R].lower():
                return False
            L += 1
            R -= 1
        # Return true if no mismatch was found while moving L/R pointers
        return True
