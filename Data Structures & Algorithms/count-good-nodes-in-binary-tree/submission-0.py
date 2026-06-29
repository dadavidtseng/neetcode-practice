# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return self.dfs(root, float("-inf"))

    def dfs(self, root, max_seen):
        if root is None:
            return 0

        counter = 1 if root.val >= max_seen else 0

        max_seen = max(max_seen, root.val)

        left = self.dfs(root.left, max_seen)
        right = self.dfs(root.right, max_seen)

        return counter + left + right
