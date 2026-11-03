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
    void solve(TreeNode* root, int targetSum, long long prefixSum,
               unordered_map<long long, long long>& sumMap, int& count) {
        if (!root)
            return;

        prefixSum += root->val;
        if (sumMap.count(prefixSum - targetSum))
            count += sumMap[prefixSum - targetSum];
        sumMap[prefixSum] += 1;

        solve(root->left, targetSum, prefixSum, sumMap, count);
        solve(root->right, targetSum, prefixSum, sumMap, count);
        sumMap[prefixSum] -= 1;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> sumMap = {{0, 1}};
        int count = 0;
        solve(root, targetSum, 0, sumMap, count);

        return count;
    }
};