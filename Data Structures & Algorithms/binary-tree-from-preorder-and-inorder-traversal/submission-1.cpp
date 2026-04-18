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
        
        std::unordered_map<int, int> inorderMap;    // value, index
        int nums = inorder.size();

        for(int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return buildTree(preorder, inorder, inorderMap, 0, nums-1, 0, nums-1);
    }

    TreeNode* buildTree(vector<int> const& preorder, vector<int> const& inorder, unordered_map<int, int>& inorderMap, int preLo, int preHi, int inLo, int inHi) {
        if(preLo > preHi || inLo > inHi) 
        {
            return nullptr;
        }

        int rootNum = preorder[preLo];
        TreeNode* root = new TreeNode(rootNum);
        int midIdx = inorderMap[rootNum];     // position of root in ORIGINAL inorder
        int leftSize = midIdx - inLo;         // how many nodes are in the left subtree

        root->left = buildTree(preorder, inorder, inorderMap, preLo + 1,          preLo + leftSize, inLo,         midIdx - 1);
        root->right = buildTree(preorder, inorder, inorderMap, preLo + leftSize+1, preHi,             midIdx + 1,  inHi);

        return root;
    }
};
