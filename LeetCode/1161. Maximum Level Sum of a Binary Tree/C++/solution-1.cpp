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
        queue<TreeNode*> nodes;
        nodes.push(root);
        int maxValue = INT_MIN, maxLevel = 1;
        int level = 0;

        while (!nodes.empty()) {
            int size = nodes.size();
            long long sum = 0;
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode* front = nodes.front();
                nodes.pop();
                sum += front->val;

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
            if ((long long)maxValue < sum) {
                maxValue = sum;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
};