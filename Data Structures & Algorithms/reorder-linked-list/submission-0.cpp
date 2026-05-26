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
        // find the middle node in the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the list in half
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        second = slow->next;
        slow->next = nullptr;
        first = head;

        // reverse the second list
        prev = nullptr;
        ListNode* curr = second;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        second = prev;

        // iterate the first haft and insert the second half on after another in first half
        while (first != nullptr && second != nullptr) {
            ListNode* tempFirst = first->next;
            ListNode* tempSecond = second->next;

            first->next = second;
            second->next = tempFirst;

            first = tempFirst;
            second = tempSecond;
        }
    }
};
