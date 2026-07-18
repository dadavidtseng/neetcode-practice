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
        auto serialize = [&](this auto&& self, TreeNode* node) -> string {
            if (node == nullptr) {
                return "$#";
            }
            return "$" + to_string(node->val) + self(node->left) + self(node->right);
        };

        auto zFunction = [&](const string& s) -> vector<int> {
            int sSize = static_cast<int>(s.length());
            vector<int> z(sSize, 0);
            int L = 0;
            int R = 0;

            for (int i = 0; i < sSize; ++i) {
                if (i <= R) {
                    z[i] = min(R - i + 1, z[i - L]);
                }
                while (i + z[i] < sSize && s[z[i]] == s[i + z[i]]) {
                    z[i]++;
                }
                if (i + z[i] - 1 > R) {
                    L = i;
                    R = i + z[i] - 1;
                }
            }
            return z;
        };

        string rootString = serialize(root);
        string subRootString = serialize(subRoot);
        string combined = subRootString + "|" + rootString;

        int subRootSize = static_cast<int>(subRootString.length());
        vector<int> z = zFunction(combined);

        for (int i = subRootSize + 1; i < static_cast<int>(combined.length()); ++i) {
            if (z[i] == subRootSize) {
                return true;
            }
        }

        return false;
    }
};
