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
    void solve(TreeNode* root, vector<string>& ans, string& comb) {
        if (!root)
            return;

        string temp = comb;

        if (!temp.empty())
            temp.append("->");
        temp.append(to_string(root->val));

        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string comb;
        solve(root, ans, comb);
        return ans;
    }
};