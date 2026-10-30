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
private:
    void solve(TreeNode* root, int maxValueSoFar, int& count) {
        if (!root)
            return;

        maxValueSoFar = max(maxValueSoFar, root->val);

        if (maxValueSoFar == root->val)
            count += 1;

        solve(root->left, maxValueSoFar, count);
        solve(root->right, maxValueSoFar, count);
    }

public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxValueSoFar = INT_MIN;
        solve(root, maxValueSoFar, count);
        return count;
    }
};