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
    TreeNode* solve(const vector<int>& preorder, int& index, int left,
                    int right) {
        if (index == preorder.size() || preorder[index] <= left ||
            preorder[index] >= right)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = solve(preorder, index, left, root->val);
        root->right = solve(preorder, index, root->val, right);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve(preorder, index, INT_MIN, INT_MAX);
    }
};