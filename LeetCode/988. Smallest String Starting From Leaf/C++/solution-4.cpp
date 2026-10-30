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

        comb.push_back('a' + root->val);
        if (!root->left && !root->right) {
            string temp = comb;
            reverse(temp.begin(), temp.end());
            if (best.empty())
                best = temp;
            else
                best = min(best, temp);
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