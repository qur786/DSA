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

        int l = solve(root->left);
        if (l == INT_MIN)
            return l;

        int r = solve(root->right);
        if (r == INT_MIN)
            return r;

        if (abs(l - r) > 1)
            return INT_MIN;

        return 1 + max(l, r);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int val = solve(root);

        return val != INT_MIN;
    }
};