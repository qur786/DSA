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
    void solve(TreeNode* root, string& comb, string& ans) {
        if (!root)
            return;

        comb.push_back(root->val + 'a');

        if (!root->left && !root->right) {
            string temp = comb;
            reverse(temp.begin(), temp.end());
            if (ans.empty())
                ans = temp;
            else
                ans = min(ans, temp);
            comb.pop_back();
            return;
        }
        solve(root->left, comb, ans);
        solve(root->right, comb, ans);
        comb.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string comb, ans;
        solve(root, comb, ans);

        return ans;
    }
};