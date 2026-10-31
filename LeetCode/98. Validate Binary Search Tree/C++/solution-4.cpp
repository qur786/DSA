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
    bool solve(TreeNode* root, long long lowerBound, long long upperBound) {
        if (!root)
            return true;

        if (root->val <= lowerBound || root->val >= upperBound)
            return false;

        return solve(root->left, lowerBound, root->val) &&
               solve(root->right, root->val, upperBound);
    }

public:
    bool isValidBST(TreeNode* root) { return solve(root, LLONG_MIN, LLONG_MAX); }
};