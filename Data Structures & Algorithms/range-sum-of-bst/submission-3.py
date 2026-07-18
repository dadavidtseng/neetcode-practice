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
"""
A Binary Search Tree (BST) is a type of binary tree data structure in which each node contains a unique key and satisfies a specific ordering property:

All nodes in the left subtree of a node contain values strictly less than the node’s value.
All nodes in the right subtree of a node contain values strictly greater than the node’s value.
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
            if node.val > low:
                s.append(node.left)
            if node.val < high:
                s.append(node.right)
            
        return result
