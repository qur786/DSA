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
    int solve(TreeNode* root, int& best) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;

        int l = solve(root->left, best);
        int r = solve(root->right, best);

        best = max(best, l + r);

        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;
        solve(root, best);
        return best;
    }
};