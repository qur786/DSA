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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int, int>& inorderIndex, int left, int right,
                    int size, int& index) {
        if (index < 0 || left > right)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[index--]);
        int inIndex = inorderIndex[root->val];
        root->right = solve(inorder, postorder, inorderIndex, inIndex + 1,
                            right, size, index);
        root->left = solve(inorder, postorder, inorderIndex, left, inIndex - 1,
                           size, index);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        int size = inorder.size();
        int index = size - 1;

        for (int i = 0; i < size; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return solve(inorder, postorder, inorderIndex, 0, size - 1, size,
                     index);
    }
};