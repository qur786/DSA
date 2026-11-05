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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    unordered_map<int, int>& inorderIndex, int left, int right,
                    int size, int& index) {
        if (index >= size || left > right)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);
        int inIndex = inorderIndex[root->val];
        root->left = solve(preorder, inorder, inorderIndex, left, inIndex - 1,
                           size, index);
        root->right = solve(preorder, inorder, inorderIndex, inIndex + 1, right,
                            size, index);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        unordered_map<int, int> inorderIndex;

        for (int i = 0; i < size; i++) {
            inorderIndex[inorder[i]] = i;
        }

        int index = 0;
        return solve(preorder, inorder, inorderIndex, 0, size - 1, size, index);
    }
};