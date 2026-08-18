class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        queue<int> nodes;
        visited[0] = true;
        nodes.push(0);
        vector<vector<pair<int, int>>> adj(n);
        int reorder = 0;

        for (const auto& connection : connections) {
            int x = connection[0], y = connection[1];
            adj[x].emplace_back(y, 1);
            adj[y].emplace_back(x, 0);
        }

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (auto [n, dir] : adj[node]) {
                if (!visited[n]) {
                    if (dir)
                        reorder++;
                    visited[n] = true;
                    nodes.push(n);
                }
            }
        }

        return reorder;
    }
};