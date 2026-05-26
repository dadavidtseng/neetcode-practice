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
        ListNode* slow    = head;
        ListNode* fast    = head;
        ListNode dummy(0, head);
        ListNode* preSlow = &dummy;

        for (int i = 0; i < n-1; i++)
        {
            fast = fast->next;
        }

        while (fast->next != nullptr)
        {
            preSlow = slow;
            slow    = slow->next;
            fast    = fast->next;
        }

        ListNode* temp = slow->next;
        preSlow->next        = temp;

        return dummy.next;
    }
};
