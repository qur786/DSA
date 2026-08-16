class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<vector<pair<int, int>>> adj(n);
        int minReo = 0;

        for (const auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1}); // 1 left -> right
            adj[connection[1]].push_back({connection[0], 0}); // 0 right <- left
        }

        queue<int> nodes;
        nodes.push(0);
        visited[0] = true;

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            for (const auto& node : adj[front]) {
                auto [n, direction] = node;
                if (!visited[n]) {
                    nodes.push(n);
                    visited[n] = true;
                    if (direction)
                        minReo++;
                }
            }
        }

        return minReo;
    }
};