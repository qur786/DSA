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
    void solve(TreeNode* root, int value, int& sum) {
        if (!root)
            return;

        value = value * 10 + root->val;
        if (!root->left && !root->right)
            sum += value;

        solve(root->left, value, sum);
        solve(root->right, value, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int value = 0, sum = 0;
        solve(root, value, sum);

        return sum;
    }
};