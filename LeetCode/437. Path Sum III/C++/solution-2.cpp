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
    void solve(TreeNode* root, const int& targetSum, long long prefixSum,
               unordered_map<long long, long long>& sumMap, int& result) {
        if (!root)
            return;

        prefixSum += root->val;

        if (sumMap.count(prefixSum - targetSum))
            result += sumMap[prefixSum - targetSum];
        sumMap[prefixSum] += 1;

        solve(root->left, targetSum, prefixSum, sumMap, result);
        solve(root->right, targetSum, prefixSum, sumMap, result);
        sumMap[prefixSum] -= 1;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        unordered_map<long long, long long> sumMap = {{0, 1}};
        solve(root, targetSum, 0LL, sumMap, result);

        return result;
    }
};