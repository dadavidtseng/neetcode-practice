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
        // preorder: root->left->right
        // inorder : left->root->right
        // Get the root from preorder[0]
        // Get leftsubtree from inorder[0] to the element before root
        // The rest is right tree
        
        if(preorder.size() == 0) 
        {
            return nullptr;
        }

        int nums = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        std::vector<int> leftPreorder;
        std::vector<int> leftInorder;
        std::vector<int> rightPreorder;
        std::vector<int> rightInorder;

        for(int i = 0; i < nums; i++)
        {
            if(inorder[i] == preorder[0])
            {
                break;
            }
            leftInorder.push_back(inorder[i]);
        }

        for(int j = 1; j < leftInorder.size() +1; j++)        
        {
            leftPreorder.push_back(preorder[j]);
        }

        for(int k = leftInorder.size()+1; k < nums; k++)        
        {
            rightPreorder.push_back(preorder[k]);
            rightInorder.push_back(inorder[k]);
        }

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
