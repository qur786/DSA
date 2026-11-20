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
    void solve(TreeNode* root, int& best, int depth) {
        if (!root)
            return;

        depth += 1;
        best = max(best, depth);
        solve(root->left, best, depth);
        solve(root->right, best, depth);
    }

public:
    int maxDepth(TreeNode* root) {
        int best = 0;
        solve(root, best, 0);

        return best;
    }
};