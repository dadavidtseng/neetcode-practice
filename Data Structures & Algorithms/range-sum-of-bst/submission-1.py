"""
Understand:
Provided a tree and [low, high], return the sum of nodes that are within low/high
Example1, (3,8), 5+3+8+4+7=27
Example2, (2,4), 4+3+2=9
All nodes' values are unique

Match:
BFS, Intervals

Plan:
Do a BFS from root, add the value of node if it's within low/high values inclusively
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root is None:
            return 0

        result = 0
        s = []
        s.append(root)

        while s:
            node = s.pop()
            
            if node is None:
                continue
            if low <= node.val <= high:
                result += node.val
            s.append(node.left)
            s.append(node.right)
        return result
