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
private:
    void BFS(TreeNode* root, int level, vector<vector<int>>& bfs) {
        if (!root)
            return;

        if (level == bfs.size())
            bfs.push_back({});

        bfs[level].push_back(root->val);

        BFS(root->left, level + 1, bfs);
        BFS(root->right, level + 1, bfs);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> bfs;
        this->BFS(root, 0, bfs);
        return bfs;
    }
};