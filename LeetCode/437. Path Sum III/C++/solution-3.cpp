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
    void solve(TreeNode* root, unordered_map<long long, long long>& sumMap,
               long long prefixSum, int targetSum, int& count) {
        if (!root)
            return;

        prefixSum += root->val;
        if (sumMap.count(prefixSum - targetSum))
            count += sumMap[prefixSum - targetSum];
        sumMap[prefixSum] += 1;
        solve(root->left, sumMap, prefixSum, targetSum, count);
        solve(root->right, sumMap, prefixSum, targetSum, count);
        sumMap[prefixSum] -= 1;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        long long prefixSum = 0;
        unordered_map<long long, long long> sumMap = {{0, 1}};
        solve(root, sumMap, prefixSum, targetSum, count);
        return count;
    }
};