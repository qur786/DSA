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
    int kthSmallest(TreeNode* root, int& k) {
        if (!root)
            return -1;

        int leftValue = kthSmallest(root->left, k);
        if (leftValue != -1)
            return leftValue;
        k -= 1;
        if (k == 0)
            return root->val;
        int rightValue = kthSmallest(root->right, k);
        if (rightValue != -1)
            return rightValue;

        return -1;
    }
};