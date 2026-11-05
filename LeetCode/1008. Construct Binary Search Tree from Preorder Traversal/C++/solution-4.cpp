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
    TreeNode* solve(vector<int>& preorder, int size, int& index,
                    int upBoundary) {
        if (index >= size || preorder[index] >= upBoundary)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder, size, index, root->val);
        root->right = solve(preorder, size, index, upBoundary);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0, size = preorder.size();
        return solve(preorder, size, index, INT_MAX);
    }
};