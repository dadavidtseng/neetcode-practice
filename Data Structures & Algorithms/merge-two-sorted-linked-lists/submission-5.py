# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        # Allocate a dummy ListNode in stack and assign curr to it for iteration purpose
        dummy = ListNode()
        curr = dummy

        # Exit the while loop when either of list1 and list2 is empty
        # 1. Attach the chosen node to curr
        # 2. Advance curr
        # 3. Advance the chosen list
        while list1 and list2:
            if list1.val <= list2.val:
                curr.next = list1
                curr = curr.next
                list1 = list1.next
            else:
                curr.next = list2
                curr = curr.next
                list2 = list2.next

        # Attach the remain list to curr based on whose left
        curr.next = list1 or list2

        return dummy.next
