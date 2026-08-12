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
        vector<vector<int>> bfs;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = -1;

        while (!nodes.empty()) {
            int size = nodes.size();
            level++;
            bfs.push_back({});

            for (int i = 0; i < size; i++) {
                TreeNode* front = nodes.front();
                nodes.pop();

                bfs.back().push_back(front->val);

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
        }

        return bfs;
    }
};