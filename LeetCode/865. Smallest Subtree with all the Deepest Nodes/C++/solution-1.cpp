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
    pair<int, TreeNode*> solve(TreeNode* root, int depth) {
        if (!root)
            return make_pair(0, nullptr);

        if (!root->left && !root->right)
            return make_pair(depth, root);

        auto [d1, l] = solve(root->left, depth + 1);
        auto [d2, r] = solve(root->right, depth + 1);

        return d1 == d2  ? make_pair(d1, root)
               : d1 < d2 ? make_pair(d2, r)
                         : make_pair(d1, l);
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto [maxDepth, ans] = solve(root, 0);

        return ans;
    }
};