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
    int answer = 0;
    pair<int, int> average(TreeNode* root) {
        if (!root)
            return make_pair(0, 0);

        auto s1 = average(root->left);
        auto s2 = average(root->right);

        int sum = root->val + s1.first + s2.first;
        int count = s1.second + s2.second + 1;

        if (sum / count == root->val)
            answer++;

        return make_pair(sum, s1.second + s2.second + 1);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        average(root);

        return answer;
    }
};