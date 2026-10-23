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
    void solve(TreeNode* root, int sumSoFar, int targetSum,
               vector<vector<int>>& answer, vector<int>& path) {
        if (!root) {
            return;
        }

        sumSoFar += root->val;
        path.push_back(root->val);

        if (!root->left && !root->right) {
            if (sumSoFar == targetSum) {
                answer.push_back(path);
            }
            path.pop_back();
            return;
        }

        solve(root->left, sumSoFar, targetSum, answer, path);
        solve(root->right, sumSoFar, targetSum, answer, path);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return {};
        vector<vector<int>> answer;
        vector<int> path;
        solve(root, 0, targetSum, answer, path);

        return answer;
    }
};