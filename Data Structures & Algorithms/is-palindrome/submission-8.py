class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_s = ""

        # Iterate through s;
        # Lowercase that character if it's alphanumeric to reconstruct s as newS
        for c in s:
            if c.isalnum():
                new_s += c.lower()
        # Return true if newS equals to its reverse
        return new_s == new_s[::-1]
