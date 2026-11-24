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
    void solve(TreeNode* root, vector<string>& answer, const string& comb) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            answer.push_back(comb.empty() ? to_string(root->val)
                                          : comb + "->" + to_string(root->val));
            return;
        }

        solve(root->left, answer,
              comb.empty() ? to_string(root->val)
                           : comb + "->" + to_string(root->val));
        solve(root->right, answer,
              comb.empty() ? to_string(root->val)
                           : comb + "->" + to_string(root->val));
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string comb;
        solve(root, answer, comb);
        return answer;
    }
};