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
        Node* cloneNode = new Node(node->val);
        unordered_map<Node*, Node*> nodeMap = {
            {node, cloneNode}}; // org => clone
        queue<Node*> nodes;
        nodes.push(node);

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            auto cloneFront = nodeMap[front];
            int size = front->neighbors.size();

            for (auto n : front->neighbors) {
                if (!nodeMap.count(n)) {
                    nodeMap[n] = new Node(n->val);
                    nodes.push(n);
                }
                auto nodeToPush = nodeMap[n];
                cloneFront->neighbors.push_back(nodeToPush);
            }
        }

        return cloneNode;
    }
};