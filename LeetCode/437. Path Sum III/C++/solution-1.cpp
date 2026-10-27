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
               int& count, long long prefixSum, int targetSum) {
        if (!root)
            return;

        prefixSum += root->val;

        if (sumMap.count(prefixSum - targetSum))
            count += sumMap[prefixSum - targetSum];
        sumMap[prefixSum] += 1;

        solve(root->left, sumMap, count, prefixSum, targetSum);
        solve(root->right, sumMap, count, prefixSum, targetSum);
        sumMap[prefixSum] -= 1;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> sumMap = {{0, 1}};
        int count = 0;
        solve(root, sumMap, count, 0LL, targetSum);
        return count;
    }
};