# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Return early if the root node doesn't exist
        if head is None:
            return None

        # prev initially is None because we don't know root node(head)'s previous node
        prev = None
        curr = head

        # Exist the loop when we've exhausted the linkedlist
        # 1. Temporaily store the next node
        # 2. Reverse the current node by pointing it to previous node
        # 3. Advance previous node by assigning current node to it
        # 4. Advance current node by assigning next node(temp) to it
        # Note that we're not change the value because we are only "reversing" the linkedlist
        while curr is not None:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev
