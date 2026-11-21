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
    long long solve(TreeNode* root, long long& tilt) {
        if (!root)
            return 0;

        int l = solve(root->left, tilt);
        int r = solve(root->right, tilt);

        tilt += abs(l - r);

        return l + r + root->val;
    }

public:
    int findTilt(TreeNode* root) {
        long long tilt = 0;
        solve(root, tilt);

        return tilt;
    }
};