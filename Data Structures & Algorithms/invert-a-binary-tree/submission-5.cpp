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

        queue<TreeNode*> q;
        q.push(root);

        // Exit the while loop when the queue is empty
        while (!q.empty()) {
            // Get the node from the queue to process
            // and remove that node form the queue
            TreeNode* node = q.front();
            q.pop();

            // Swap the node's left and right children
            swap(node->left, node->right);

            // Push the swapped left and right children into the queue
            // for next procesing iteration in the while loop
            // Note that we only push existed child into the queue
            // because there's nothing to process if that child node doesn't exist
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        // Return the modified tree's root node
        return root;
    }
};
