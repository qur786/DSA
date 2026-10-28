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
    void solve(TreeNode* root, int& prevVal, int& res) {
        if (!root)
            return;

        solve(root->left, prevVal, res);
        if (prevVal != -1)
            res = min(res, root->val - prevVal);
        prevVal = root->val;
        solve(root->right, prevVal, res);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int prevVal = -1, res = INT_MAX;
        solve(root, prevVal, res);
        return res;
    }
};