"""
Understanding:
Given a number n, build a staircase where ith row has exactly i coins
For example,
n=4, we can build 1+2+1,   return 2 complete rows
n=9, we can build 1+2+3+3, return 3 complete rows

Planning:
1. Perform a 1+2+3+...+n in a while loop
2. Count the iteration index as we go
3. If current sum of (1+2+3+...+n) is greater than provided n, return that number
4. Otherwise, increment that iteration index and continue the iteration
Time: O(n)
Space: O(1)
"""


class Solution:
    def arrangeCoins(self, n: int) -> int:
        row = 0

        while n - row > 0:
            row += 1
            n -= row
        return row
