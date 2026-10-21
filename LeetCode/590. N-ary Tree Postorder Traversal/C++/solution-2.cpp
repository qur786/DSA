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
        stack<Node *> st;
        vector<int> output;
        Node * curr = nullptr;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);


                curr = curr -> left;
            }

            auto top = st.top();

            if (top -> children && top -> children[0] != lastVisited) {
                curr = top -> children;
            } else {
                lastVisited = top;
                output.push_back(top -> val);
                st.pop();
            }
        }
    }
};