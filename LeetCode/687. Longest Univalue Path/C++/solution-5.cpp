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

        int leftVal = 0, rightVal = 0;

        auto l = solve(root->left, best);
        auto r = solve(root->right, best);

        if (root->left && root->left->val == root->val)
            leftVal = l + 1;
        if (root->right && root->right->val == root->val)
            rightVal = r + 1;

        best = max(best, leftVal + rightVal);

        return max(leftVal, rightVal);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int best = 0;
        solve(root, best);

        return best;
    }
};