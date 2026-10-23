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
public:
    int sumNumbers(TreeNode* root, int numSoFar = 0) {
        if (!root)
            return numSoFar;

        int val = root->val;
        numSoFar = numSoFar * 10 + val;

        if (!root->left && !root->right)
            return numSoFar;

        int sum1 = 0, sum2 = 0;

        if (root->left)
            sum1 = sumNumbers(root->left, numSoFar);
        if (root->right)
            sum2 = sumNumbers(root->right, numSoFar);

        return sum1 + sum2;
    }
};