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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<vector<int>> answer;

        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> temp;
            temp.reserve(size);

            for (int i = 0; i < size; i++) {
                auto front = nodes.front();
                nodes.pop();

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
                temp.push_back(front->val);
            }
            answer.push_back(move(temp));
        }

        return answer;
    }
};