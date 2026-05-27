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
        int n = static_cast<int>(lists.size());

        // return nullptr if the lists is empty
        if (n == 0) return nullptr;

        // exit when n == 1
        while (n > 1) {
            // reset newSize after a merge
            int newSize = 0;

            // iterate the lists with 2 steps
            for (int i = 0; i < n; i += 2) {
                // odd lists, store the last list back to lists
                if (i + 1 == n) {
                    lists[newSize] = lists[i];
                } else {
                    // merge two lists and store back to lists[newSize]
                    lists[newSize] = mergeTwoLists(lists[i], lists[i + 1]);
                }

                // calculate newSize
                // lists will be shrunk after every operation
                newSize++;
            }

            // update the n with newSize
            // this will shrink size of the lists
            n = newSize;
        }

        // return the merged list
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* listA, ListNode* listB) {
        // initialize a dummy node and attach a tail node on that dummy node
        ListNode dummy(0, nullptr);
        ListNode* tail = &dummy;

        // exit the loop when listA and listB are both exhausted
        while (listA != nullptr && listB != nullptr) {
            // when listA's value is smaller than listB's value
            // 1. attach listA to tail
            // 2. advance listA
            if (listA->val < listB->val) {
                tail->next = listA;
                listA = listA->next;
            }
            // when listA's value is larger or equal to listB's value
            // 1. attach listB to tail
            // 2. advance listB
            else {
                tail->next = listB;
                listB = listB->next;
            }

            // advance tail
            tail = tail->next;
        }

        // attach the remaining of listA and listB
        tail->next = (listA != nullptr) ? listA : listB;

        // return the head of the merged list
        return dummy.next;
    }
};
