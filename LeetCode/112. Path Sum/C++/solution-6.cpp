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
    bool solve(TreeNode* root, int runningSum, int targetSum) {
        if (!root)
            return false;

        runningSum += root->val;

        if (!root->left && !root->right) {
            if (targetSum == runningSum)
                return true;
            return false;
        }

        return solve(root->left, runningSum, targetSum) ||
               solve(root->right, runningSum, targetSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, 0, targetSum);
    }
};