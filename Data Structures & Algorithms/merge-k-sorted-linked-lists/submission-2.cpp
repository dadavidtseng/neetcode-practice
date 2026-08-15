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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;

        for (int i = 0; i < static_cast<int>(lists.size()); ++i) {
            while (lists[i] != nullptr) {
                nodes.push_back((lists[i]->val));
                lists[i] = lists[i]->next;
            }
        }
        sort(nodes.begin(), nodes.end());

        ListNode* result = new ListNode(0);
        ListNode* curr = result;

        for (int i = 0; i < static_cast<int>(nodes.size()); ++i) {
            curr->next = new ListNode(nodes[i]);
            curr = curr->next;
        }
        return result->next;
    }
};
