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
        vector<int> sizes;
        nodes.push(root);
        sizes.push_back(1);
        int level = 0;

        while (!nodes.empty()) {
            sizes[level]--;

            if (sizes.size() == (level + 1))
                sizes.push_back(0);

            if (nodes.front()->left) {
                sizes[level + 1]++;
                nodes.push(nodes.front()->left);
            }
            if (nodes.front()->right) {
                sizes[level + 1]++;
                nodes.push(nodes.front()->right);
            }

            TreeNode* node = nodes.front();
            nodes.pop();

            if (bfs.size() == level)
                bfs.push_back(vector<int>(1, node->val));
            else
                bfs[level].push_back(node->val);

            if (sizes[level] == 0)
                level++;
        }

        return bfs;
    }
};