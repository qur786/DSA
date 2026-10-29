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
    void solve(TreeNode* root, int depth, int& best) {
        if (!root)
            return;

        depth += 1;

        if (!root->left && !root->right) {
            best = min(best, depth);
            return;
        }

        solve(root->left, depth, best);

        solve(root->right, depth, best);
    }

public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int best = INT_MAX;
        solve(root, 0, best);

        return best;
    }
};