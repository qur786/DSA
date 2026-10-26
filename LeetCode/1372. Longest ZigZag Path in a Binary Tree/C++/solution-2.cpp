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
    void solve(TreeNode* root, bool isLeft, int step, int& best) {
        if (!root)
            return;

        best = max(best, step);

        if (isLeft) {
            solve(root->left, false, step + 1, best);
            solve(root->right, true, 1, best);
        } else {
            solve(root->right, true, step + 1, best);
            solve(root->left, false, 1, best);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        int best1 = 0, best2 = 0;
        solve(root, false, 0, best1);
        solve(root, true, 0, best2);

        return max(best1, best2);
    }
};