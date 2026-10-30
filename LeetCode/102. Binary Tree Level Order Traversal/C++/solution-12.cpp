/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++) {
                auto node = nodes.front();
                nodes.pop();
                temp[i] = node->val;

                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
            }
            result.push_back(move(temp));
        }

        return result;
    }
};