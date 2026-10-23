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
    void solve(TreeNode* root, vector<int>& answer, int count) {
        if (!root)
            return;

        if (answer.size() == count) {
            answer.push_back(root->val);
        }

        solve(root->right, answer, count + 1);
        solve(root->left, answer, count + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        int count = 0;
        vector<int> answer;
        solve(root, answer, count);
        return answer;
    }
};