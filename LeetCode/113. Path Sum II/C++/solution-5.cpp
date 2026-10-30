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
    void solve(TreeNode* root, vector<int>& comb, vector<vector<int>>& answer,
               int sum, int targetSum) {
        if (!root)
            return;

        sum += root->val;
        comb.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == targetSum)
                answer.push_back(comb);
        }

        solve(root->left, comb, answer, sum, targetSum);
        solve(root->right, comb, answer, sum, targetSum);
        comb.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> comb;
        int sum = 0;
        solve(root, comb, answer, 0, targetSum);

        return answer;
    }
};