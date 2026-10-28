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
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int prevVal = -1;
        int res = INT_MAX;

        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            auto node = st.top();
            st.pop();
            if (prevVal == -1)
                prevVal = node->val;
            else {
                res = min(res, node->val - prevVal);
                prevVal = node->val;
            }
            curr = node->right;
        }

        return res;
    }
};