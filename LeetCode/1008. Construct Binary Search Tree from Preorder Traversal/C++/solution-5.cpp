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
    TreeNode* solve(vector<int>& preorder, int& index, int maxVal) {
        if (index >= preorder.size())
            return nullptr;

        if (preorder[index] >= maxVal)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = solve(preorder, index, root -> val);
        root->right = solve(preorder, index, maxVal);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0, maxVal = INT_MAX;
        return solve(preorder, index, maxVal);
    }
};