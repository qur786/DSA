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
    void solve(TreeNode* root, int minValue, int maxValue, int& ans) {
        if (!root)
            return;

        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);

        if (!root->left && !root->right) {
            ans = max(ans, maxValue - minValue);
            return;
        }

        solve(root->left, minValue, maxValue, ans);
        solve(root->right, minValue, maxValue, ans);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, INT_MAX, INT_MIN, ans);

        return ans;
    }
};