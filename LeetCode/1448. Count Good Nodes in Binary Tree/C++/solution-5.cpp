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
    void solve(TreeNode* root, int maxVal, int& best) {
        if (!root)
            return;

        maxVal = max(maxVal, root->val);
        if (maxVal == root->val)
            best += 1;
        solve(root->left, maxVal, best);
        solve(root->right, maxVal, best);
    }

public:
    int goodNodes(TreeNode* root) {
        int best = 0;
        solve(root, INT_MIN, best);

        return best;
    }
};