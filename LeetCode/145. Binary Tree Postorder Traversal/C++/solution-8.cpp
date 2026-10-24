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
        vector<int> answer;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;

        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            auto node = st.top();

            if (node->right && lastVisited != node->right) {
                root = node->right;
            } else {
                answer.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }

        return answer;
    }
};