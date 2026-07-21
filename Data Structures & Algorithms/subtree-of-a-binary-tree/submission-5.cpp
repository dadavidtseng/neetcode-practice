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

        auto serialize = [](this auto&& self, TreeNode* node) -> string {
            // Return "$#" if this node is empty
            if (node == nullptr) {
                return "$#";
            }
            // Return the serialized tree string after pushing node's left/right nodes into DFS
            return "$" + to_string(node->val) + self(node->left) + self(node->right);
        };

        auto zFunction = [](const string& s) -> vector<int> {
            // 1. z[i] = length of the longest common prefix between s[i...] and s[0...]
            // 2. Maintain the rightmost Z-box [L, R), where s[L...R-1] == s[0...(R-L)-1]
            int sSize = static_cast<int>(s.length());
            vector<int> z(sSize, 0);
            int L = 0;
            int R = 0;

            // Compute z[i] for every suffix starting at i
            for (int i = 1; i < sSize; ++i) {
                // If i falls inside the current Z-box, we can reuse the previously computed
                // value at i - L. However, the match cannot extend beyond the current Z-box,
                // so we cap it at R - i.
                if (i < R) {
                    z[i] = min(R - i, z[i - L]);
                }

                // Try to extend the current match beyond the Z-box
                // z[i] is the current matched prefix length
                while (i + z[i] < sSize && s[z[i]] == s[i + z[i]]) {
                    z[i]++;
                }

                // If we extended farther than the current Z-box,
                // update it to the new rightmost Z-box
                if (i + z[i] > R) {
                    L = i;
                    R = i + z[i];
                }
            }
            return z;
        };

        // 1. Serialize text from root
        // 2. Serialize pattern from subRoot
        // 3. Combine pattern, delimeter, and text
        // Z-function compares every suffix with the prefix of the combined string.
        // Therefore, we put pattern at the beginning so that z[i] tells us how much
        // the current suffix matches the pattern.
        string text = serialize(root);
        string pattern = serialize(subRoot);
        string combined = pattern + "|" + text;

        int patternLength = static_cast<int>(pattern.length());
        int combinedLength = static_cast<int>(combined.length());
        vector<int> z = zFunction(combined);

        // From patternLength + 1 to the end,
        // if z[i] equals patternLength, that means pattern is in text
        for (int i = patternLength + 1; i < combinedLength; ++i) {
            if (z[i] == patternLength) {
                return true;
            }
        }
        return false;
    }
};
