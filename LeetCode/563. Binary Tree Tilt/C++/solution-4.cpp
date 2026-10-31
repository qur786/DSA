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
    int solve(TreeNode* root, int& ans) {
        if (!root)
            return 0;

        int l = solve(root->left, ans);
        int r = solve(root->right, ans);

        ans += abs(l - r);

        return l + r + root->val;
    }

public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        solve(root, ans);

        return ans;
    }
};