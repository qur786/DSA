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
        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool isRight = true;

        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++) {
                auto front = nodes.front();
                nodes.pop();
                temp[isRight ? i : size - i - 1] = front->val;
                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
            result.push_back(move(temp));
            isRight = !isRight;
        }

        return result;
    }
};