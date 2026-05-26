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
        ListNode* result = nullptr;

        for (int i = 0; i < lists.size(); ++i)
        {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }

    ListNode* mergeTwoLists(ListNode* listA, ListNode* listB)
    {
        ListNode  dummy(0, nullptr);
        ListNode* tail = &dummy;

        while (listA != nullptr && listB != nullptr)
        {
            if (listA->val < listB->val)
            {
                tail->next = listA;
                listA = listA->next;
                
            }
            else
            {
                tail->next = listB;
                listB = listB->next;
            }
            
            tail = tail->next ;
        }
        
        tail->next = (listA != nullptr) ? listA : listB;

        return dummy.next;
    }
};
