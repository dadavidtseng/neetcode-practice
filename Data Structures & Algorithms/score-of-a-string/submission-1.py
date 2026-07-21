"""
Understand:
Provided a string, the definition of a score is the absolute difference between
the ASCII values of adjacent characters, return the sum of scores for the string.

s is made up of lowercase English letters.
2 <= s.length <= 100

s= "code"
'c'= 99, 'o'= 111, 'd'= 100, 'e'= 101
score_c_o= |99-111|  = 12
score_o_d= |111-100| = 11
score_d_e= |100-101| = 1
score = 24

Match:
String

Plan:
Iterate through the string, calculate the score as we go
"""


class Solution:
    def scoreOfString(self, s: str) -> int:
        result = 0

        for i in range(1, len(s)):
            result += abs(ord(s[i]) - ord(s[i - 1]))
        return result
