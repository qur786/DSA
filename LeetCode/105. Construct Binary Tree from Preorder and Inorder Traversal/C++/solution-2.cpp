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
                    unordered_map<int, int>& inorderIndex, int& index, int left,
                    int right) {
        if (index == preorder.size() || left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[index++]);

        int inIndex = inorderIndex[root->val];

        root->left =
            solve(preorder, inorder, inorderIndex, index, left, inIndex - 1);
        root->right =
            solve(preorder, inorder, inorderIndex, index, inIndex + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        int size = inorder.size();
        int index = 0;

        for (int i = 0; i < size; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return solve(preorder, inorder, inorderIndex, index, 0,
                     preorder.size() - 1);
    }
};