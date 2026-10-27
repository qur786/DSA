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
    int solve(TreeNode* root, int& best) {
        if (!root)
            return 0;

        int l = max(0, solve(root->left, best));
        int r = max(0, solve(root->right, best));

        best = max(best, l + r + root->val);

        return root->val + max(l, r);
    }

public:
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        solve(root, best);
        return best;
    }
};