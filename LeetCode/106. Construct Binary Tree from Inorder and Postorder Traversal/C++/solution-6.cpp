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
    TreeNode* solve(vector<int>& postorder,
                    unordered_map<int, int>& inorderIndex, int& index,
                    int start, int end) {
        if (start > end)
            return nullptr;

        int val = postorder[index--];
        int mid = inorderIndex[val];

        TreeNode* root = new TreeNode(val);

        root->right = solve(postorder, inorderIndex, index, mid + 1, end);
        root->left = solve(postorder, inorderIndex, index, start, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        int size = inorder.size();

        for (int i = 0; i < size; i++) {
            inorderIndex[inorder[i]] = i;
        }

        int index = size - 1;

        return solve(postorder, inorderIndex, index, 0, size - 1);
    }
};