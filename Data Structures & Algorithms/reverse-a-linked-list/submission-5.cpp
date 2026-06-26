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
        // Base case of the recursive call, which means that we've reached the last node
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* newHead = head;

        // Keep recursing as long as the next node exists
        // 1. When hitting the base case at the last node:
        //      - new_head stays as head (the new head of reversed list)
        // 2. When starting to unwind:
        //      - head is one node before the last node
        //      - head.next is the last node
        //      - "head.next.next = head": Reverse!
        if (head->next != nullptr) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }

        // Make the original first node points to None
        head->next = nullptr;

        // Pass along the last node(new head) to first node(new tail)
        return newHead;
    }
};
