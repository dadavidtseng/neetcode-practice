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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            k++;
            curr = curr->next;
        }

        const int removeIdx = k - n;

        // Return early without doing the removal
        if (removeIdx == 0) {
            return head->next;
        }

        curr = head;

        for (int i = 0; i < k-1; ++i) {
            if (i + 1 == removeIdx) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
