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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> st;
        int best = INT_MAX, preValue = -1;

        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            auto node = st.top();
            st.pop();

            if (preValue != -1)
                best = min(best, node->val - preValue);
            preValue = node->val;
            curr = node->right;
        }

        return best;
    }
};