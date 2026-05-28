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

class Codec {
   public:
    // Encodes a tree to a single string.
    static string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N";
        }

        string result;
        serialize(root, result);

        return result;
    }

    static void serialize(TreeNode const* node, string& result) {
        if (node == nullptr) {
            result.append("N,");
            return;
        }

        result += to_string(node->val) + ",";

        serialize(node->left, result);
        serialize(node->right, result);
    }

    // Decodes your encoded data to tree.
    static TreeNode* deserialize(string data) {
        if (data == "N") {
            return nullptr;
        }

        stringstream ss(data);

        return deserialize(ss);
    }

    static TreeNode* deserialize(stringstream& ss) {
        string token;
        getline(ss, token, ',');

        if (token == "N") {
            return nullptr;
        }

        TreeNode* result = new TreeNode(stoi(token));
        result->left = deserialize(ss);
        result->right = deserialize(ss);

        return result;
    }
};
