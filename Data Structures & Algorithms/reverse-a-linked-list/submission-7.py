# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Base case of the recursive call, which means that we've reached the last node
        if head is None:
            return None

        new_head: Optional[ListNode] = head

        # Keep recursing as long as the next node exists
        # 1. When hitting the base case at the last node:
        #   - new_head stays as head (the new head of reversed list)
        # 2. When starting to unwind:
        #   - head is one node before the last node
        #   - head.next is the last node
        #   - "head.next.next = head": Reverse!
        if head.next is not None:
            new_head = self.reverseList(head.next)
            head.next.next = head

        # Make the original first node points to None
        head.next = None

        # Pass along the last node(new head) to first node(new tail)
        return new_head
