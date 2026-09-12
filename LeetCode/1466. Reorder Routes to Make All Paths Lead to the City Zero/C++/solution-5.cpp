class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> visited(n, false);
        queue<int> nodes;

        for (const auto& connection : connections) {
            adj[connection[0]].emplace_back(connection[1], 0);
            adj[connection[1]].emplace_back(connection[0], 1);
        }

        nodes.push(0);
        visited[0] = true;
        int count = 0;

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            for (const auto& [value, dir] : adj[front]) {
                if (!visited[value]) {
                    visited[value] = true;
                    if (!dir)
                        count++;
                    nodes.push(value);
                }
            }
        }

        return count;
    }
};