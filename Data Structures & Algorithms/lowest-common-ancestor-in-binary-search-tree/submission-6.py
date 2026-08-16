# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def dfs(node: "TreeNode") -> "TreeNode":
            # If current node's value is greater than p's and q's value, go left
            if node.val > p.val and node.val > q.val:
                return dfs(node.left)

            # If current node's value is less than p's and q's value, go right
            if node.val < p.val and node.val < q.val:
                return dfs(node.right)

            # Return the lowest common ancestor
            return node

        # Return empty if any of root, p, and q is empty
        if not root or not p or not q:
            return None
        return dfs(root)
