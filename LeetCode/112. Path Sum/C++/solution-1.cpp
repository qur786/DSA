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
    bool solve(TreeNode* root, int sum, int targetSum) {
        if (!root)
            return false;

        sum += root->val;

        if (!root->left && !root->right) {
            if (sum == targetSum)
                return true;
            else
                return false;
        }

        if (solve(root->left, sum, targetSum))
            return true;
        if (solve(root->right, sum, targetSum))
            return true;

        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return solve(root, 0, targetSum);
    }
};