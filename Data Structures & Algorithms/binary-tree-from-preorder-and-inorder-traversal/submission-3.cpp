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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create preIdx and inIdx to keep track of where we are in preorder and inorder
        int preIdx = 0;
        int inIdx = 0;

        // Note that we only care about preoder's size because we are building the tree using
        // preorder as boundary. For inorder, we use it to know whether we should build left/right
        // subtrees and that has nothing to do with its size.
        const int preorderSize = static_cast<int>(preorder.size());

        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;

        // Exit the while loop when eith preIdx or inIdx equal or greater than preorder's size
        while (preIdx < preorderSize && inIdx < preorderSize) {
            //
            curr->right = new TreeNode(preorder[preIdx], nullptr, curr->right);
            curr = curr->right;
            preIdx++;

            // Exit the while loop when we finished processing preorder or
            while (preIdx < preorderSize && curr->val != inorder[inIdx]) {
                curr->left = new TreeNode(preorder[preIdx], nullptr, curr);
                curr = curr->left;
                preIdx++;
            }
            inIdx++;

            while (curr->right != nullptr && inIdx < preorderSize &&
                   curr->right->val == inorder[inIdx]) {
                TreeNode* root = curr->right;
                curr->right = nullptr;
                curr = root;
                inIdx++;
            }
        }
        return dummy->right;
    }
};
