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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = -1;

        while (!nodes.empty()) {
            int size = nodes.size();
            level++;
            averages.push_back(0.0);
            long long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* front = nodes.front();
                nodes.pop();

                sum += front->val;

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
            averages[level] = (double)sum / size;
        }

        return averages;
    }
};