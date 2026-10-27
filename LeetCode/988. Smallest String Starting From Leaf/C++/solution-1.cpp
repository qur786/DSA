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
    void solve(TreeNode* root, const string& comb, string& best) {
        if (!root)
            return;

        string temp = comb;
        temp.push_back(root -> val + 'a');

        if (!root->left && !root->right) {
            reverse(temp.begin(), temp.end());
            best = best.empty() ? temp : temp < best ? temp : best;
        }
        solve(root->left, temp, best);
        solve(root->right, temp, best);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string comb, best;
        solve(root, comb, best);

        return best;
    }
};