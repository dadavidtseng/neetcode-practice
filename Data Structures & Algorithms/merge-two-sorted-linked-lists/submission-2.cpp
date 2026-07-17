/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Allocate a dummy ListNode in stack and assign curr to it for iteration purpose
        ListNode dummy;
        ListNode* curr = &dummy;

        // Exit the while loop when either of list1 and list2 is empty
        // 1. Attach the chosen node to curr
        // 2. Advance curr
        // 3. Advance the chosen list
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }

        // Attach the remain list to curr based on whose left
        curr->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};
