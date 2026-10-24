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
    void solve(TreeNode* root, int& count, int maxValue) {
        if (!root)
            return;

        maxValue = max(maxValue, root->val);

        if (root->val == maxValue)
            count += 1;
        solve(root->left, count, maxValue);
        solve(root->right, count, maxValue);
    }

public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root, count, INT_MIN);

        return count;
    }
};