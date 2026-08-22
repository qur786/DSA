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

        queue<Node*> nodes;
        unordered_map<Node*, Node*> graphMap;
        nodes.push(node);
        Node* cloneHead = new Node(node->val);
        graphMap[node] = cloneHead;

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            auto cloneNode = graphMap[front];
            for (const auto& n : front->neighbors) {
                if (!graphMap.count(n)) {
                    graphMap[n] = new Node(n->val);
                    nodes.push(n);
                }
                cloneNode->neighbors.push_back(graphMap[n]);
            }
        }

        return cloneHead;
    }
};