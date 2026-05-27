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
    int maxPathSum(TreeNode* root) {
        // return 0 if root node is nullptr to prevent crashing
        if (root == nullptr) {
            return 0;
        }

        // initialize the result to INT_MIN for all negative nodes case
        int result = INT_MIN;

        // pass the result by reference in to helper function for recursive call
        maxPathSum(root, result);

        return result;
    }

    int maxPathSum(TreeNode const* node, int& sum) {
        // return 0 if this node is nullptr to prevent crashing
        if (node == nullptr) {
            return 0;
        }

        TreeNode const* cur = node;
        int leftSum = 0;
        int rightSum = 0;

        // if current node's left child exists
        // get the best chain from the left subtree, ignore if negative
        // leftSum is equal to the outcome if it's greater than 0
        if (cur->left != nullptr) {
            leftSum = max(0, maxPathSum(cur->left, sum));
        }
        // if current node's right child exists
        // the best chain from the right subtree, ignore if negative
        // rightSum is equal to the outcome if it's greater than 0
        if (cur->right != nullptr) {
            rightSum = max(0, maxPathSum(cur->right, sum));
        }

        // update the passed in sum
        // if leftSum + cur->val + rightSum is greater than sum
        // this is the only thing current node cases about
        sum = max(sum, leftSum + cur->val + rightSum);

        // return current node's value + whichever is greater among leftSum and rightSum
        return cur->val + max(leftSum, rightSum);
    }
};
