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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<vector<int>> result;
        bool reverseOrder = false;

        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> levelVector(size);

            for (int i = 0; i < size; i++) {
                TreeNode* front = nodes.front();
                nodes.pop();
                int index = reverseOrder ? size - i - 1 : i;
                levelVector[index] = front->val;

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
            reverseOrder = !reverseOrder;
            result.push_back(move(levelVector));
        }

        return result;
    }
};