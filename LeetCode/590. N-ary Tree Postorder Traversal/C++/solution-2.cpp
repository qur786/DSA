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
        stack<pair<Node*, bool>> st;
        vector<int> output;
        st.emplace(root, false);

        while (!st.empty()) {
            auto [top, childVisited] = st.top();

            if (childVisited) {
                output.push_back(top->val);
                st.pop();
            } else {
                st.top().second = true;
                for (auto it = top->children.rbegin();
                     it != top->children.rend(); it++) {
                    st.emplace(*it, false);
                }
            }
        }

        return output;
    }
};