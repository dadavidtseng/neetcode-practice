class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        memo = {}
        return min(self.dfs(cost, 0, memo), self.dfs(cost, 1, memo))

    def dfs(self, cost, i, memo) -> int:
        if i >= len(cost):
            return 0

        if i in memo:
            return memo[i]

        memo[i] = cost[i] + min(self.dfs(cost, i + 1, memo), self.dfs(cost, i + 2, memo))
        return memo[i]
