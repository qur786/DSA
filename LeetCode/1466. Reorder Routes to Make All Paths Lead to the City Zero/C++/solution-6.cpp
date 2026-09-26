class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(
            n); // first -> value, second -> direction, 0 -> a to b, 1 -> b to a
        vector<bool> visited(n, false);
        queue<int> nodes;
        int change = 0;

        for (const auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];

            adj[u].emplace_back(v, 0);
            adj[v].emplace_back(u, 1);
        }
        visited[0] = true;
        nodes.push(0);

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();

            for (const auto [child, dir] : adj[front]) {
                if (!visited[child]) {
                    visited[child] = true;
                    if (!dir)
                        change++;
                    nodes.push(child);
                }
            }
        }

        return change;
    }
};