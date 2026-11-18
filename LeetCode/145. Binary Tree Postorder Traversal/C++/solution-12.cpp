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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};

        vector<int> answer;
        stack<TreeNode*> nodes;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (!nodes.empty() || curr) {
            while (curr) {
                nodes.push(curr);
                curr = curr->left;
            }

            auto node = nodes.top();

            if (node->right && lastVisited != node->right) {
                curr = node->right;
            } else {
                answer.push_back(node->val);
                nodes.pop();
                lastVisited = node;
            }
        }

        return answer;
    }
};