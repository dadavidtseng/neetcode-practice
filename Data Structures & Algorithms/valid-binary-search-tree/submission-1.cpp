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
    bool isValidBST(TreeNode* root) {
        // return true if root is nullptr
        if (root == nullptr) {
            return true;
        }

        // 1. current node is root
        // 2. previous node's value for comparison
        // 3. a stack for LIFO
        TreeNode* cur = root;
        long long pre = LLONG_MIN;
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
            cur = s.top();
            s.pop();

            // if current node's value is less than previous node, return false
            // this should always be increasing because we're doing in-order traversing
            if (cur->val <= pre) {
                return false;
            }

            // records the current node and goes right
            pre = cur->val;
            cur = cur->right;
        }

        return true;
    }
};
