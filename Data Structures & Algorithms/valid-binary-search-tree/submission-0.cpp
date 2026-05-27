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
        // return nullptr result if root is nullptr
        if (root == nullptr) {
            return true;
        }

        TreeNode* cur = root;
        long long pre = LLONG_MIN;
        stack<TreeNode*> s;

        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();

            if (cur->val <= pre) {
                return false;
            }

            pre = cur->val;
            cur = cur->right;

            s.pop();
        }

        return true;
    }
};
