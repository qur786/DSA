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
        queue<Node*> orgNodes, newNodes;
        orgNodes.push(node);
        newNodes.push(cloneHead);
        unordered_map<int, Node*> nodeMap = {{1, cloneHead}};

        while (!orgNodes.empty()) {
            Node* orgNode = orgNodes.front();
            orgNodes.pop();
            Node* newNode = newNodes.front();
            newNodes.pop();

            for (Node* orgN : orgNode->neighbors) {
                Node* newN = nullptr;
                if (nodeMap.count(orgN->val)) {
                    newN = nodeMap[orgN->val];
                } else {
                    newN = new Node(orgN->val);
                    orgNodes.push(orgN);
                    newNodes.push(newN);
                    nodeMap[orgN->val] = newN;
                }
                newNode->neighbors.push_back(newN);
            }
        }

        return cloneHead;
    }
};