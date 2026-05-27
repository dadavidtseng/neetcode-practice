/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        // 1. current node is root
        // 2. a stack for LIFO
        TreeNode* cur = root;
        stack<TreeNode*> s;

        // exit the loop when current node is nullptr and the stack is empty
        while (cur != nullptr || !s.empty()) {
            // exit the loop when current node is nullptr,
            // otherwise, push the current node into stack
            // and keep going left
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }

            // 1. set current node to the top of the stack
            // this is essentially visiting that node
            // 2. remove the visited node since we don't need it anymore
            // 3. decrease k by 1
            cur = s.top();
            s.pop();
            k--;

            // if k is 0, that mean we've reached our goal, return the current node's value
            if (k == 0) {
                return cur->val;
            }

            // move the current node to right
            cur = cur->right;
        }

        // we'll never reach this because 1 <= k <= n
        return 0;
    }
};
