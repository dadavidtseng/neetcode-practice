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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root's value is greater than p and q's value, go left
        if (root->val > p->val && root->val > q->val) {
            root = lowestCommonAncestor(root->left, p, q);
        }
        // if root's value is less than p and q's value, go right
        else if (root->val < p->val && root->val < q->val) {
            root = lowestCommonAncestor(root->right, p, q);
        }

        // otherwise, return root because we've found the lowest common ancestor
        return root;
    }
};
