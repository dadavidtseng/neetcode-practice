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
    ListNode* reverseList(ListNode* head) {
        // Return early if the root node doesn't exist
        if (head == nullptr) {
            return nullptr;
        }

        // prev initially is None because we don't know root node(head)'s previous node
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Exist the loop when we've exhausted the linked list
        // 1. Temporarily store the next node
        // 2. Reverse the current node by pointing it to previous node
        // 3. Advance previous node by assigning current node to it
        // 4. Advance current node by assigning next node(temp) to it
        // Note that we're not change the value because we are only "reversing" the linked list
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
