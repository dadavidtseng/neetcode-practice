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
        // Return true if root and subRoot are both empty
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }

        // Return false if one of root and subRoot is not empty
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        auto serialize = [&](this auto&& self, TreeNode* node) -> string {
            // Return "$#" if this node is empty
            if (node == nullptr) {
                return "$#";
            }
            // Return the serialized tree string after pushing node's left/right nodes into DFS
            return "$" + to_string(node->val) + self(node->left) + self(node->right);
        };

        auto buildLPS = [&](const string& pattern) -> vector<int> {
            int patternLength = static_cast<int>(pattern.length());
            vector<int> lps(patternLength, 0);

            for (int i = 1; i < patternLength; ++i) {
                int j = lps[i - 1];

                while (j > 0 && pattern[i] != pattern[j]) {
                    j = lps[j - 1];
                }
                if (pattern[i] == pattern[j]) {
                    j++;
                }
                lps[i] = j;
            }
            return lps;
        };

        string text = serialize(root);
        string pattern = serialize(subRoot);
        int textLength = static_cast<int>(text.length());
        int patternLength = static_cast<int>(pattern.length());

        // Build the LPS (failure) table for the pattern
        vector<int> lps = buildLPS(pattern);

        // Search for pattern in text
        int j = 0;

        for (int i = 0; i < textLength; ++i) {
            // While there's a mismatch, we fallback to the index that's already a match instead of
            // starting from 0
            while (j > 0 && text[i] != pattern[j]) {
                j = lps[j - 1];
            }
            // Advance j if it's currently a match
            if (text[i] == pattern[j]) {
                j++;
            }
            // Return true if pattern is found in text
            if (j == patternLength) {
                return true;
            }
        }
        // Return false if nothing was found
        return false;
    }
};
