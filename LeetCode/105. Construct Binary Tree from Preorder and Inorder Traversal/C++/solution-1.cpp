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
                    unordered_map<int, int>& inorderIndex, int l, int r,
                    int& index) {
        if (l > r)
            return nullptr;
        int val = preorder[index];
        int inIndex = inorderIndex[val];

        TreeNode* root = new TreeNode(val);
        index++;
        root->left =
            solve(preorder, inorder, inorderIndex, l, inIndex - 1, index);
        root->right =
            solve(preorder, inorder, inorderIndex, inIndex + 1, r, index);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        int size = inorder.size();

        for (int i = 0; i < size; i++)
            inorderIndex[inorder[i]] = i;

        int index = 0;

        return solve(preorder, inorder, inorderIndex, 0, size - 1, index);
    }
};