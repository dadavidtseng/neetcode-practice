"""
Understand:
Provided a piles with even number elements, the sum of the piles is odd
This guarantees that one of Alice and Bob is going to have a greater number of stones.
Ex. [1,2,3,1],
Alice 1, Bob 2, Alice 3, Bob 1 -> Alice 1+3, Bob 2+1 -> Alice wins
              , Alice 1, Bob 3 -> Alice 1+1, Bob 2+3 -> Bob wins
       , Bob 1, Alice 2, Bob 3 -> Alice 1+2, Bob 1+3 -> Bob wins
              , Alice 3, Bob 2 -> Alice 1+3, Bob 1+2 -> Alice wins
Since the problem says that Alice and Bob will always play optimally,
so in this case, whoever starts first will win the game.
Note that we could return true, but let's write out the recursive solution

Match:
Recursion, DP

Plan:
We can maintain a dp that represents Alice's max total using left/right pointers. Alice only picks when the current piles's element is even number.
"""


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        # Create a dp to store key (L, R) with value of Alice's max total
        dp = {}

        def dfs(L: int, R: int) -> int:
            if L > R:
                return 0
            if (L, R) in dp:
                return dp[(L, R)]
            is_even = True if (R - L) % 2 else False
            left = piles[L] if is_even else 0
            right = piles[R] if is_even else 0

            dp[(L, R)] = max(dfs(L + 1, R) + left, dfs(L, R - 1) + right)
            return dp[(L, R)]

        total = sum(piles)
        alice = dfs(0, len(piles) - 1)
        return alice > total - alice
