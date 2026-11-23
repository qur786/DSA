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
    void solve(TreeNode* root, int depth, int& minDepth) {
        if (!root)
            return;

        depth += 1;

        if (!root->left && !root->right)
            minDepth = min(depth, minDepth);

        solve(root->left, depth, minDepth);
        solve(root->right, depth, minDepth);
    }

public:
    int minDepth(TreeNode* root) {
        int depth = 0, minDepth = INT_MAX;
        solve(root, depth, minDepth);

        return minDepth == INT_MAX ? 0 : minDepth;
    }
};