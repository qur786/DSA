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
    void solve(TreeNode* root, string& comb, string& best) {
        if (!root)
            return;

        comb.push_back(root->val + 'a');

        if (!root->left && !root->right) {
            string res = comb;
            reverse(res.begin(), res.end());
            best = best.empty() ? res : res < best ? res : best;
        }
        solve(root->left, comb, best);
        solve(root->right, comb, best);
        comb.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string comb, best;
        solve(root, comb, best);

        return best;
    }
};