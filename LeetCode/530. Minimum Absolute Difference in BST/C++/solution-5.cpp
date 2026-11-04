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
        stack<TreeNode*> nodes;
        int prevVal = -1;
        int minDiff = INT_MAX;

        while (curr || !nodes.empty()) {
            while (curr) {
                nodes.push(curr);
                curr = curr->left;
            }

            auto node = nodes.top();
            nodes.pop();

            if (prevVal != -1)
                minDiff = min(minDiff, abs(prevVal - node->val));
            prevVal = node->val;
            curr = node->right;
        }

        return minDiff;
    }
};