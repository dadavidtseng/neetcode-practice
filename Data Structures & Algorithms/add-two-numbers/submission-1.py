# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode()
        temp_result = result
        carry = 0

        while l1 is not None or l2 is not None or carry != 0:
            temp1 = 0
            temp2 = 0
            total = 0
            
            if l1 is not None:
                temp1 = l1.val
                l1 = l1.next
            
            if l2 is not None:
                temp2 = l2.val
                l2 = l2.next

            total = temp1 + temp2 + carry
            
            if total >= 10:
                carry = 1
                total -= 10
            else:
                carry = 0

            temp_result.val = total
            if l1 is not None or l2 is not None or carry != 0:
                temp_result.next = ListNode()
                temp_result = temp_result.next
            
        return result