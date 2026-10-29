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
                    unordered_map<int, int>& inorderIndexMap, int l, int r,
                    int& index) {
        if (l > r)
            return nullptr;

        int val = postorder[index--];
        int inIndex = inorderIndexMap[val];

        TreeNode* root = new TreeNode(val);

        root->right =
            solve(inorder, postorder, inorderIndexMap, inIndex + 1, r, index);
        root->left =
            solve(inorder, postorder, inorderIndexMap, l, inIndex - 1, index);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndexMap;

        for (int i = 0; i < inorder.size(); i++)
            inorderIndexMap[inorder[i]] = i;
        int index = postorder.size() - 1;
        return solve(inorder, postorder, inorderIndexMap, 0,
                     postorder.size() - 1, index);
    }
};