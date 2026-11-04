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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        stack<TreeNode*> nodes;

        while (!nodes.empty() || curr) {
            while (curr) {
                nodes.push(curr);
                curr = curr->left;
            }
            auto node = nodes.top();
            nodes.pop();
            k--;
            if (k == 0)
                return node->val;

            curr = node->right;
        }

        return 0;
    }
};