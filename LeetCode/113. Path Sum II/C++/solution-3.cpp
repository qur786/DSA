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
    void solve(TreeNode* root, vector<vector<int>>& answer, vector<int>& path,
               int sum, int targetSum) {
        if (!root) {
            return;
        }

        sum += root->val;
        path.push_back(root->val);

        if (!root->left && !root->right) {
            if (sum == targetSum)
                answer.push_back(path);
        }

        solve(root->left, answer, path, sum, targetSum);
        solve(root->right, answer, path, sum, targetSum);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> answer;

        solve(root, answer, path, 0, targetSum);

        return answer;
    }
};