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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queueP;
        queue<TreeNode*> queueQ;
        queueP.push(p);
        queueQ.push(q);

        while (!queueP.empty() && !queueQ.empty()) {
            TreeNode* nodeP = queueP.front();
            TreeNode* nodeQ = queueQ.front();
            queueP.pop();
            queueQ.pop();

            if (nodeP == nullptr && nodeQ == nullptr) {
                continue;
            }
            if (nodeP == nullptr || nodeQ == nullptr) {
                return false;
            }
            if (nodeP->val != nodeQ->val) {
                return false;
            }
            queueP.push(nodeP->left);
            queueP.push(nodeP->right);
            queueQ.push(nodeQ->left);
            queueQ.push(nodeQ->right);
        }
        return true;
    }
};
