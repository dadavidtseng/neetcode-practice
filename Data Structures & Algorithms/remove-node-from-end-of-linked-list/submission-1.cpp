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
        // attach slow/fast pointer to head
        ListNode const* fast = head;

        // attach a dummy node before head to handle the head removal case
        ListNode dummy(0, head);
        ListNode* preSlow = &dummy;

        // advance the fast pointer by (n-1) times
        for (int i = 1; i < n; i++) {
            fast = fast->next;
        }

        // advance slow/fast/preSlow pointer
        // exit when reaching the last node(fast pointer's next is nullptr)
        while (fast->next != nullptr) {
            preSlow = preSlow->next;
            fast = fast->next;
        }

        // remove the node slow pointer is at,
        // which is the nth node in from the end of the list
        preSlow->next = preSlow->next->next;

        // return dummy.next(head),
        // in head removal case(single node), demmy.next is nullptr
        return dummy.next;
    }
};
