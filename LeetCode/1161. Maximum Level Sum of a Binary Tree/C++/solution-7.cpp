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
public:
    int maxLevelSum(TreeNode* root) {
        if (!root)
            return -1;
        queue<TreeNode*> nodes;
        nodes.push(root);
        long long maxSum = LLONG_MIN;
        int maxLevel = -1;
        int level = 0;

        while (!nodes.empty()) {
            int size = nodes.size();
            long long sum = 0;
            level += 1;

            for (int i = 0; i < size; i++) {
                auto front = nodes.front();
                nodes.pop();
                sum += front->val;
                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
};