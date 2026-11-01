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
    TreeNode* solve(vector<int>& preorder, int size, int upperBound,
                    int& index) {
        if (index >= size)
            return nullptr;

        if (preorder[index] >= upperBound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = solve(preorder, size, root->val, index);
        root->right = solve(preorder, size, upperBound, index);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        int index = 0;
        return solve(preorder, size, INT_MAX, index);
    }
};