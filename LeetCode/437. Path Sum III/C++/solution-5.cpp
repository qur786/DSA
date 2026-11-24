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
    void solve(TreeNode* root, unordered_map<long long, int>& sumMap, long long prefixSum,
               int targetSum, int& ans) {
        if (!root)
            return;

        prefixSum += root->val;
        if (sumMap.count(prefixSum - targetSum))
            ans += sumMap[prefixSum - targetSum];
        sumMap[prefixSum] += 1;
        solve(root->left, sumMap, prefixSum, targetSum, ans);
        solve(root->right, sumMap, prefixSum, targetSum, ans);
        sumMap[prefixSum] -= 1;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> sumMap = {{0, 1}};
        int ans = 0;
        long long prefixSum = 0;
        solve(root, sumMap, prefixSum, targetSum, ans);
        return ans;
    }
};