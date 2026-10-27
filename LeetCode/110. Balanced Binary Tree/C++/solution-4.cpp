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

        int left = solve(root->left);
        int right = solve(root->right);

        if (left == INT_MAX || right == INT_MAX || abs(right - left) > 1)
            return INT_MAX;

        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        return solve(root) != INT_MAX;
    }
};