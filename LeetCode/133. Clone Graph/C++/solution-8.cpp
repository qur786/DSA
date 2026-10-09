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
        Node* cloneNode = new Node(node->val);
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[node] = cloneNode;
        queue<Node*> nodes;
        nodes.emplace(node);

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            auto clonedNode = nodeMap[front];

            for (auto child : front->neighbors) {
                if (!nodeMap.count(child)) {
                    nodeMap[child] = new Node(child->val);
                    nodes.push(child);
                }
                clonedNode->neighbors.push_back(nodeMap[child]);
            }
        }

        return cloneNode;
    }
};