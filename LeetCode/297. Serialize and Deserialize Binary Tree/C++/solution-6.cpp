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
        queue<TreeNode*> nodes;
        nodes.push(root);
        string result;

        while (!nodes.empty()) {
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                auto node = nodes.front();
                nodes.pop();
                if (!result.empty())
                    result.push_back(',');
                result.append(node ? to_string(node->val) : "#");

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

        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        TreeNode* curr = root;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            if (getline(ss, token, ','))
                node->left = token == "#" ? nullptr : new TreeNode(stoi(token));
            if (getline(ss, token, ','))
                node->right =
                    token == "#" ? nullptr : new TreeNode(stoi(token));

            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));