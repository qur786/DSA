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
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;

        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            auto node = st.top();

            if (node->right && node->right != lastVisited) {
                root = node->right;
            } else {
                lastVisited = node;
                answer.push_back(node->val);
                st.pop();
            }
        }

        return answer;
    }
};