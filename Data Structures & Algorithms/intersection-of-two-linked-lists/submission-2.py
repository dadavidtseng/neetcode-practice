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
"""


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        a = 0
        b = 0
        curr_a = headA
        curr_b = headB
        while curr_a:
            curr_a = curr_a.next
            a += 1

        while curr_b:
            curr_b = curr_b.next
            b += 1
        print(f"a={a}, b={b}")
        curr_a = headA
        curr_b = headB

        if a < b:
            for _ in range(b-a):
                curr_b = curr_b.next
        elif a > b:
            for _ in range(a-b):
                curr_a = curr_a.next
        
        k = min(a, b)

        for _ in range(k):
            if curr_a == curr_b:
                return curr_a

            curr_a = curr_a.next
            curr_b = curr_b.next

        return None
