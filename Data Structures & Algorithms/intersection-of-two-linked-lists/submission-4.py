# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
"""
Understanding:
Provided two linkedlist headA and headB, return the intersecting node if they intersects.
Return None otherwise.

Planning:
Iterate through two linkedlist, check if the node shares the same memory address as we go
Starts from the node where we align their last node, so we can check if they are on the same node

   4->1->8->4->5
5->6->1->8->4->5

Review:
We could iterate through them and when they reach the end, just make one jumps to another's head
This way, they'll meet at either intersection node or the end by using O(m+n) time complexity at most,
which is the same as we compute the length for both of them explicitly.
"""


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        curr_a = headA
        curr_b = headB

        while curr_a != curr_b:
            curr_a = curr_a.next if curr_a else headA
            curr_b = curr_b.next if curr_b else headB
        return curr_a
