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
    void solve(TreeNode* root, int depth, int& maxDepth) {
        if (!root)
            return;

        depth += 1;

        if (!root->left && !root->right) {
            maxDepth = max(maxDepth, depth);
            return;
        }

        solve(root->left, depth, maxDepth);
        solve(root->right, depth, maxDepth);
    }

public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        solve(root, 0, maxDepth);

        return maxDepth;
    }
};