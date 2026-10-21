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
    void post(Node* root, vector<int>& output) {
        if (!root)
            return;

        for (auto& child : root->children)
            post(child, output);
        output.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> output;
        post(root, output);

        return output;
    }
};