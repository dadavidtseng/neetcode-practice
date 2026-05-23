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
    bool hasCycle(ListNode* head) {
        // iterate through the linked list and store them in an unordered_set
        unordered_set<ListNode*> container;

        while (head != nullptr) {
            // if the listnode appeared before, return true
            if (container.contains(head)) {
                return true;
            }

            container.insert(head);  // store the node in the container
            head = head->next;       // advance the node list
        }

        // if we reach the end of the linked list, there will be no cycle, return false
        return false;
    }
};
