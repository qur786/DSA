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
    void solve(TreeNode* root, int targetSum, int runningSum,
               vector<vector<int>>& answer, vector<int>& comb) {
        if (!root)
            return;
        runningSum += root->val;
        comb.push_back(root->val);

        if (!root->left && !root->right) {
            if (targetSum == runningSum)
                answer.push_back(comb);
        }

        solve(root->left, targetSum, runningSum, answer, comb);
        solve(root->right, targetSum, runningSum, answer, comb);
        comb.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> comb;
        vector<vector<int>> answer;
        solve(root, targetSum, 0, answer, comb);
        return answer;
    }
};