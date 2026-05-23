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
        ListNode dummy;              // create a dummy node
        ListNode* current = &dummy;  // current tail node iterator

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;    // attach the chosen node to the merged list
                current = current->next;  // advance the tail
                list1 = list1->next;      // advance the chosen node list
            } else {
                current->next = list2;    // attach the chosen node to the merged list
                current = current->next;  // advance the tail
                list2 = list2->next;      // advance the chosen node list
            }
        }

        // attach the remain node to the merged list based on whose left
        current->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};
