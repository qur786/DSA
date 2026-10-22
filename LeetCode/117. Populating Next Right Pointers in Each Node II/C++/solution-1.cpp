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

            for (int i = 0; i < size; i++) {
                auto front = nodes.front();
                nodes.pop();

                if (i < size - 1)
                    front->next = nodes.front();

                if (front->left)
                    nodes.push(front->left);
                if (front->right)
                    nodes.push(front->right);
            }
        }

        return root;
    }
};