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
    int solve(TreeNode* root, int& maxD) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;

        int l = solve(root->left, maxD);
        int r = solve(root->right, maxD);

        maxD = max(maxD, l + r);

        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        solve(root, maxD);

        return maxD;
    }
};