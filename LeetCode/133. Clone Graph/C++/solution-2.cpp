/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        Node* cloneHead = new Node(node->val);
        queue<Node*> orgNodes;
        orgNodes.push(node);
        unordered_map<Node*, Node*> nodeMap = {{node, cloneHead}};

        while (!orgNodes.empty()) {
            Node* front = orgNodes.front();
            orgNodes.pop();
            Node* curr = nodeMap[front];

            for (Node* n : front->neighbors) {
                if (!nodeMap.count(n)) {
                    nodeMap[n] = new Node(n->val);
                    orgNodes.push(n);
                }

                Node* newN = nodeMap[n];
                curr->neighbors.push_back(newN);
            }
        }

        return cloneHead;
    }
};