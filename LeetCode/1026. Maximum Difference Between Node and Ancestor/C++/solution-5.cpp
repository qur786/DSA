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
    void solve(TreeNode* root, int minVal, int maxVal, int& ans) {
        if (!root)
            return;

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        ans = max(ans, maxVal - minVal);
        solve(root->left, minVal, maxVal, ans);
        solve(root->right, minVal, maxVal, ans);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
};