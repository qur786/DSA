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
    TreeNode* solve(vector<int>& preorder,
                    unordered_map<int, int>& inorderIndex, int& index, int size,
                    int start, int end) {
        if (start > end)
            return nullptr;

        int val = preorder[index++];
        int mid = inorderIndex[val];
        TreeNode* root = new TreeNode(val);

        root->left = solve(preorder, inorderIndex, index, size, start, mid - 1);
        root->right = solve(preorder, inorderIndex, index, size, mid + 1, end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        unordered_map<int, int> inorderIndex;

        for (int i = 0; i < size; i++)
            inorderIndex[inorder[i]] = i;

        int index = 0;

        return solve(preorder, inorderIndex, index, size, 0, size - 1);
    }
};