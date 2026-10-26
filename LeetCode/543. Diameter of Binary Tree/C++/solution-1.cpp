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
    int best(TreeNode* root, int& b) {
        if (!root)
            return 0;

        int l = best(root->left, b);
        int r = best(root->right, b);

        b = max(b, l + r);

        return 1 + max(l, r);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int b = 0;
        best(root, b);

        return b;
    }
};