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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;

        // return nullptr result if root is nullptr
        if (root == nullptr) {
            return result;
        }

        // push the root so the while loop can start
        q.push(root);

        // exist when the queue is empty, which means that we've finished everything
        while (!q.empty()) {
            // get the current level size from the queue
            // this will not include the null node
            int const levelSize = static_cast<int>(q.size());
            vector<int> level;  // a container for storing current level's nodes

            // iterate through the queue
            // it should only contain current level's nodes
            for (int i = 0; i < levelSize; i++) {
                // read the front node and add its value to level
                TreeNode const* front = q.front();
                level.push_back(front->val);

                // push its children into queue(if they exist)
                if (front->left != nullptr) {
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    q.push(front->right);
                }

                // remove the front node since we don't need it anymore
                q.pop();
            }

            // the level container should now contain current level's nodes in right order
            // stores it in result
            result.push_back(level);
        }

        return result;
    }
};
