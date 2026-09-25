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
            auto front = nodes.front();
            nodes.pop();

            for (auto child : front->neighbors) {
                if (!nodeMap.count(child)) {
                    nodeMap[child] = new Node(child->val);
                    nodes.push(child);
                }
                nodeMap[front]->neighbors.push_back(nodeMap[child]);
            }
        }

        return cloneHead;
    }
};