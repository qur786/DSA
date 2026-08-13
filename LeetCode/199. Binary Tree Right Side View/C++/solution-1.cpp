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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> result;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                auto front = nodes.front();
                nodes.pop();
                if (i == size - 1)
                    result.push_back(front->val);

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
        }

        return result;
    }
};