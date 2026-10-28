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
        stack<TreeNode*> st;
        vector<int> answer;
        TreeNode *curr = root, *lastVisited = nullptr;

        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            auto node = st.top();

            if (node->right && lastVisited != node->right) {
                curr = node->right;
            } else {
                answer.push_back(node->val);
                st.pop();
                lastVisited = node;
            }
        }

        return answer;
    }
};