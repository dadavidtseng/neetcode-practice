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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Check if p and q are the exact same tree using DFS
        auto isSameTree = [&](this auto&& self, TreeNode* p, TreeNode* q) -> bool {
            // Return true if both nodes are empty
            if (p == nullptr && q == nullptr) {
                return true;
            }

            // If both nodes aren't empty and they have the same value,
            // push their left/right nodes into recursive call
            if (p != nullptr && q != nullptr && p->val == q->val) {
                return self(p->left, q->left) && self(p->right, q->right);
            }

            // Return false if none of the above checks match
            return false;
        };

        // Return true if root and subRoot are both empty
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }

        // Return false if one of root and subRoot is not empty
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        // Return true if root and subRoot are the same tree
        if (isSameTree(root, subRoot)) {
            return true;
        }

        // Push in root's left/right nodes into two recursive calls if root and subRoot are not the
        // same tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
