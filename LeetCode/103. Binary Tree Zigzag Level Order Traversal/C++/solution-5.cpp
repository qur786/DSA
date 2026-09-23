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
        vector<vector<int>> answer;
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool isReverse = false;

        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++) {
                auto front = nodes.front();
                nodes.pop();
                temp[isReverse ? size - i - 1 : i] = front->val;

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
            isReverse = !isReverse;
            answer.push_back(move(temp));
        }

        return answer;
    }
};