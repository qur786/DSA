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
    pair<TreeNode*, int> solve(TreeNode* root, int depth) {
        if (!root)
            return make_pair(nullptr, 0);

        depth += 1;

        if (!root->left && !root->right)
            return make_pair(root, depth);

        const auto& [t1, d1] = solve(root->left, depth);
        const auto& [t2, d2] = solve(root->right, depth);

        return d1 == d2  ? make_pair(root, d1)
               : d1 > d2 ? make_pair(t1, d1)
                         : make_pair(t2, d2);
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        const auto& [tree, depth] = solve(root, 0);

        return tree;
    }
};