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
    void reorderList(ListNode* head) {
        // find the middle node in the list by using slow/fast pointer
        ListNode* slow = head;
        ListNode const* fast = head;

        // advance slow/fast pointer when
        // 1. fast pointer is not nullptr(even list)
        // 2. fast pointer's next is not nullptr(odd list)
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the list in half
        // 1. attach original head to first
        // 2. attach slow pointer's next to second(this works both on odd/even list)
        // 3. cut the second half from first half(original head)
        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse the second list
        // 1. store the next node in temp
        // 2. set the next node to pre
        // 3. advance the pre node
        // 4. advance the cur node
        // attach pre to the head of second half(cur is nullptr now)
        ListNode* pre = nullptr;
        ListNode* cur = second;

        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        second = pre;

        // iterate the first haft and insert the second half one after another in first half
        // exit the loop when second is nullptr
        // we don't need to check first because for first half is one node more than second half in
        // odd list
        while (second != nullptr) {
            ListNode* tempFirst = first->next;
            ListNode* tempSecond = second->next;

            first->next = second;
            second->next = tempFirst;

            first = tempFirst;
            second = tempSecond;
        }
    }
};
