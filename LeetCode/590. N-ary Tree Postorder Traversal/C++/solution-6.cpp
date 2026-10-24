/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void solve(Node* root, vector<int>& answer) {
        if (!root)
            return;

        for (auto& child : root->children)
            solve(child, answer);

        answer.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> answer;
        solve(root, answer);

        return answer;
    }
};