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
    TreeNode* invertTree(TreeNode* root) {
        // Return nullptr if the root is nullptr
        if (root == nullptr) {
            return nullptr;
        }

        // Swap the left and right children node
        swap(root->left, root->right);

        // Recursive call for each left and right node
        invertTree(root->left);
        invertTree(root->right);

        // Return the modified tree's root node
        return root;
    }
};
