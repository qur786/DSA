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

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                TreeNode* right = root->right;
                delete root;
                return right;
            } else if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            } else {
                TreeNode* replacement = root->right;
                TreeNode* nodeToDelete = nullptr;
                while (replacement) {
                    nodeToDelete = replacement;
                    replacement = replacement->left;
                }

                root->val = nodeToDelete->val;
                root->right = deleteNode(root->right, nodeToDelete->val);
                return root;
            }
        }

        return root;
    }
};