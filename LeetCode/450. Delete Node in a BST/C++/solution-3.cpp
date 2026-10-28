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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left || !root->right) {
                TreeNode* next = root->left ? root->left : root->right;
                delete root;
                return next;
            } else {
                TreeNode *temp = root->right, *replacement = nullptr;
                while (temp) {
                    replacement = temp;
                    temp = temp->left;
                }
                root->val = replacement->val;
                root->right = deleteNode(root->right, replacement->val);
                return root;
            }
        }

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);

        return root;
    }
};