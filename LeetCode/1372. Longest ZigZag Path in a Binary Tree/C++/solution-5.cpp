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
    void solve(TreeNode* root, bool goLeft, int len, int& best) {
        if (!root)
            return;

        if (goLeft) {
            solve(root->left, false, len + 1, best);
            solve(root->right, true, 1, best);
        } else {
            solve(root->left, false, 1, best);
            solve(root->right, true, len + 1, best);
        }
        best = max(best, len);
    }

public:
    int longestZigZag(TreeNode* root) {
        int len = 0, best = 0;
        solve(root, true, len, best);

        return best;
    }
};