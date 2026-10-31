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
    int solve(TreeNode* root, int depth) {
        if (!root)
            return depth;

        int d1 = solve(root->left, depth + 1);
        int d2 = solve(root->right, depth + 1);

        if (d1 == INT_MIN || d2 == INT_MIN)
            return INT_MIN;

        return abs(d1 - d2) <= 1 ? max(d1, d2) : INT_MIN;
    }

public:
    bool isBalanced(TreeNode* root) { return solve(root, 0) != INT_MIN; }
};