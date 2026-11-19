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
            return root;

        queue<Node*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();
            Node* curr = new Node();

            for (int i = 0; i < size; i++) {
                auto node = nodes.front();
                nodes.pop();

                if (node->left) {
                    nodes.push(node->left);
                    curr->next = node->left;
                    curr = curr->next;
                }
                if (node->right) {
                    nodes.push(node->right);
                    curr->next = node->right;
                    curr = curr->next;
                }
            }
        }

        return root;
    }
};