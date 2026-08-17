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
            return nullptr;
        unordered_map<Node*, Node*> nodeMap;
        Node* cloneHead = new Node(node->val);
        nodeMap[node] = cloneHead;
        queue<Node*> nodes;
        nodes.push(node);

        while (!nodes.empty()) {
            Node* front = nodes.front();
            nodes.pop();
            Node* cloneNode = nodeMap[front];

            for (Node* neighbor : front->neighbors) {
                if (!nodeMap.count(neighbor)) {
                    nodes.push(neighbor);
                    nodeMap[neighbor] = new Node(neighbor->val);
                }
                cloneNode->neighbors.push_back(nodeMap[neighbor]);
            }
        }

        return cloneHead;
    }
};