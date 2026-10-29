/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string result;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                auto node = nodes.front();
                nodes.pop();
                if (!result.empty())
                    result.push_back(',');
                if (node)
                    result.append(to_string(node->val));
                else
                    result.append("null");

                if (node) {
                    nodes.push(node->left);
                    nodes.push(node->right);
                }
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        string token;
        vector<int> values;

        while (getline(ss, token, ',')) {
            if (token == "null")
                values.push_back(INT_MIN);
            else
                values.push_back(stoi(token));
        }

        TreeNode* root = new TreeNode(values[0]);
        queue<TreeNode*> nodes;
        nodes.push(root);

        for (int i = 1; i < values.size() - 1; i += 2) {
            auto node = nodes.front();
            nodes.pop();
            if (values[i] != INT_MIN) {
                node->left = new TreeNode(values[i]);
                nodes.push(node->left);
            }
            if (values[i + 1] != INT_MIN) {
                node->right = new TreeNode(values[i + 1]);
                nodes.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));