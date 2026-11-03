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
    long long solve(TreeNode* root, long long& best) {
        if (!root)
            return 0;

        long long l = max(0LL, solve(root->left, best));
        long long r = max(0LL, solve(root->right, best));

        best = max(best, l + r + root->val);

        return max(l, r) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        long long best = LLONG_MIN;
        solve(root, best);

        return best;
    }
};