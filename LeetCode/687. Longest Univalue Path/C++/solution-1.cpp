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

        int l = solve(root->left, best);
        int r = solve(root->right, best);

        int leftValue = 0;
        int rightValue = 0;

        if (root->left && root->left->val == root->val)
            leftValue = l + 1;
        if (root->right && root->right->val == root->val)
            rightValue = r + 1;

        best = max(best, leftValue + rightValue);

        return max(leftValue, rightValue);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int best = 0;
        solve(root, best);

        return best;
    }
};