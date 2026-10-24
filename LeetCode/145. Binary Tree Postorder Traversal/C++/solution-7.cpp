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
    void solve(TreeNode* root, vector<int>& answer) {
        if (!root)
            return;

        solve(root->left, answer);
        solve(root->right, answer);
        answer.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        solve(root, answer);
        return answer;
    }
};