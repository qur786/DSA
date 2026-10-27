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
        string str = to_string(root->val);
        string temp = comb + (comb.empty() ? str : "->" + str);

        if (!root->left && !root->right) {
            answer.push_back(temp);
            return;
        }

        solve(root->left, answer, temp);
        solve(root->right, answer, temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string comb;

        solve(root, answer, comb);

        return answer;
    }
};