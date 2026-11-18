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
public:
    vector<int> postorder(Node* root) {
        if (!root)
            return {};

        vector<int> result;
        stack<pair<Node*, bool>> nodes;
        nodes.emplace(root, false);

        while (!nodes.empty()) {
            auto& [node, isProcessed] = nodes.top();

            if (isProcessed) {
                result.push_back(node->val);
                nodes.pop();
            } else {
                int size = node->children.size();
                for (int i = size - 1; i >= 0; i--) {
                    nodes.emplace(node->children[i], false);
                }
                isProcessed = true;
            }
        }

        return result;
    }
};