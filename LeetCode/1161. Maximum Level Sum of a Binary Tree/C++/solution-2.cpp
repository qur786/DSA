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
            return 1;
        int maxLevel = 1;
        long long maxSum = LLONG_MIN;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 0;

        while (!nodes.empty()) {
            int size = nodes.size();
            level++;
            long long sum = 0;

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