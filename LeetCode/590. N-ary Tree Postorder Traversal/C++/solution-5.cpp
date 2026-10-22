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

        vector<int> answer;
        stack<pair<Node*, bool>> st;
        st.emplace(root, false);

        while (!st.empty()) {
            auto& [node, isProcessed] = st.top();

            if (isProcessed) {
                answer.push_back(node->val);
                st.pop();
            } else {
                for (auto it = node->children.rbegin();
                     it != node->children.rend(); it++) {
                    st.emplace(*it, false);
                }
                isProcessed = true;
            }
        }

        return answer;
    }
};