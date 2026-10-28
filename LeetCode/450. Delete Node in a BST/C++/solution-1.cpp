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
            return root;
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        while (curr && curr->val != key) {
            parent = curr;
            curr = key < curr->val ? curr->left : curr->right;
        }

        if (!curr)
            return root;

        if (!curr->left && !curr->right) {
            if (curr == root)
                return nullptr;
            if (parent && parent->left == curr)
                parent->left = nullptr;
            else if (parent && parent->right == curr)
                parent->right = nullptr;
            delete curr;
            return root;
        }
        if (!curr->left || !curr->right) {
            if (!parent)
                return curr->left ? curr->left : curr->right;
            if (parent && parent->left == curr) {
                parent->left = nullptr;
                parent->left = curr->left ? curr->left : curr->right;
            }
            if (parent && parent->right == curr) {
                parent->right = nullptr;
                parent->right = curr->left ? curr->left : curr->right;
            }
            delete curr;
            return root;
        }
        TreeNode* toBeDeleted = curr;
        TreeNode* replacement = nullptr;
        curr = curr->right;
        while (curr) {
            replacement = curr;
            curr = curr->left;
        }

        toBeDeleted->val = replacement->val;

        toBeDeleted->right = deleteNode(toBeDeleted->right, replacement->val);

        return root;
    }
};