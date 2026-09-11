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
        unordered_map<Node*, Node*> nodeMap;
        queue<Node*> nodes;
        nodes.push(node);
        Node* deepClone = new Node(node->val);
        nodeMap[node] = deepClone;

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            auto currCopyNode = nodeMap[front];

            for (const auto& neighbor : front->neighbors) {
                if (!nodeMap.count(neighbor)) {
                    nodeMap[neighbor] = new Node(neighbor->val);
                    nodes.push(neighbor);
                }
                auto copyNode = nodeMap[neighbor];
                currCopyNode->neighbors.push_back(copyNode);
            }
        }

        return deepClone;
    }
};