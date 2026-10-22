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
    void rightSide(TreeNode* root, vector<int>& answer, int depth) {
        if (!root)
            return;
        if (answer.size() == depth)
            answer.push_back(root->val);
        rightSide(root->right, answer, depth + 1);
        rightSide(root->left, answer, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> answer;
        int depth = 0;

        rightSide(root, answer, depth);

        return answer;
    }
};