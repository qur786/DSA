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
    void solve(TreeNode* root, int maxValue, int minValue, int& best) {
        if (!root)
            return;

        maxValue = max(maxValue, root->val);
        minValue = min(minValue, root->val);

        best = max(best, maxValue - minValue);
        solve(root->left, maxValue, minValue, best);
        solve(root->right, maxValue, minValue, best);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int best = 0;
        solve(root, INT_MIN, INT_MAX, best);
        return best;
    }
};