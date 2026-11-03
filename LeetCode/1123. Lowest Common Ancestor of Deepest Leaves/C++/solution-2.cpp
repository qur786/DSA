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
    pair<TreeNode*, int> solve(TreeNode* root, int depth) {
        if (!root)
            return make_pair(nullptr, depth);

        auto p1 = solve(root->left, depth + 1);
        auto p2 = solve(root->right, depth + 1);

        auto [l, d1] = p1;
        auto [r, d2] = p2;

        return d1 == d2 ? make_pair(root, d1) : d1 > d2 ? p1 : p2;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto [t, d] = solve(root, 0);

        return t;
    }
};