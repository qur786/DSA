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
        vector<int> output;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            auto node = st.top();
            st.pop();

            output.push_back(node->val);

            for (auto child : node->children)
                st.push(child);
        }

        reverse(output.begin(), output.end());

        return output;
    }
};