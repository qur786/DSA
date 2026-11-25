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
        int minDiff = INT_MAX;
        int prevVal = INT_MAX;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            auto node = st.top();
            st.pop();

            if (prevVal != INT_MAX)
                minDiff = min(minDiff, node->val - prevVal);
            prevVal = node->val;

            curr = node->right;
        }

        return minDiff;
    }
};