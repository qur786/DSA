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
    void solve(TreeNode* root, bool goLeft, int path, int& best) {
        if (!root)
            return;
        best = max(best, path);
        if (goLeft) {
            solve(root->left, false, path + 1, best);
            solve(root->right, true, 1, best);
        } else {
            solve(root->left, false, 1, best);
            solve(root->right, true, path + 1, best);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        int best = 0;
        solve(root, false, 0, best);

        return best;
    }
};