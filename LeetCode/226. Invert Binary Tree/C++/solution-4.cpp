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
    TreeNode* solve(TreeNode* root) {
        if (!root)
            return root;

        auto left = solve(root->left);
        auto right = solve(root->right);

        root->left = right;
        root->right = left;

        return root;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* res = root;
        solve(root);

        return res;
    }
};