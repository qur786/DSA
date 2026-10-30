/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return {};

        queue<Node*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();
            Node* dummy = new Node();
            Node* curr = dummy;

            for (int i = 0; i < size; i++) {
                auto node = nodes.front();
                nodes.pop();

                if (node->left) {
                    curr->next = node->left;
                    curr = curr->next;
                    nodes.push(node->left);
                }
                if (node->right) {
                    curr->next = node->right;
                    curr = curr->next;
                    nodes.push(node->right);
                }
            }
        }

        return root;
    }
};