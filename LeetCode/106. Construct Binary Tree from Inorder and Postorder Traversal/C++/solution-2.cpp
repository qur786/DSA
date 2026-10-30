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
                    unordered_map<int, int>& inorderIndex, int size, int left,
                    int right, int& index) {
        if (index >= size || left > right)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[index--]);
        int inIndex = inorderIndex[root->val];
        root->right = solve(inorder, postorder, inorderIndex, size, inIndex + 1,
                            right, index);
        root->left = solve(inorder, postorder, inorderIndex, size, left,
                           inIndex - 1, index);

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

        return solve(inorder, postorder, inorderIndex, size, 0, size - 1,
                     index);
    }
};