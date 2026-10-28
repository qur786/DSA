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
        vector<int> answer;

        st.emplace(root, false);

        while (!st.empty()) {
            auto& [node, isChildrenProcessed] = st.top();
            auto children = node->children;
            if (!isChildrenProcessed) {
                for (auto it = children.rbegin(); it != children.rend(); it++) {
                    st.emplace(*it, false);
                }
                isChildrenProcessed = true;
            } else {
                answer.push_back(node->val);
                st.pop();
            }
        }

        return answer;
    }
};