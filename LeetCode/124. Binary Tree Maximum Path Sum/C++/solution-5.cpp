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
    long long solve(TreeNode* root, int& maxSum) {
        if (!root)
            return 0;

        auto l = solve(root->left, maxSum);
        auto r = solve(root->right, maxSum);

        int leftVal = max(l, 0LL), rightVal = max(r, 0LL);

        maxSum = max(maxSum, leftVal + rightVal + root->val);

        return max(leftVal, rightVal) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);

        return maxSum;
    }
};