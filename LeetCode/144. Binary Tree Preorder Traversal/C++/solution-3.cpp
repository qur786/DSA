/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode * root, vector<int> & answer) {
        if (!root) return;

        answer.push_back(root -> val);
        preorder(root -> left, answer);
        preorder(root -> right, answer);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> answer;
        preorder(root, answer);

        return answer;
    }
};