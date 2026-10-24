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
    int solve(TreeNode* root, int val) {
        if (!root)
            return 0;

        val = val * 10 + root->val;
        if (!root->left && !root->right)
            return val;

        return solve(root->left, val) + solve(root->right, val);
    }

public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        return solve(root, 0);
    }
};