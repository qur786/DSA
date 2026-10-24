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
    int solve(TreeNode* root) {
        if (!root)
            return 0;

        int leftDepth = solve(root->left);
        int rightDepth = solve(root->right);

        if (leftDepth == INT_MIN || rightDepth == INT_MIN ||
            abs(leftDepth - rightDepth) > 1)
            return INT_MIN;

        return 1 + max(leftDepth, rightDepth);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        return solve(root) != INT_MIN;
    }
};