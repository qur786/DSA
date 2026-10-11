class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        int count = 0;
        queue<int> nodes;
        vector<bool> visited(n, false);

        for (const auto& connection : connections) {
            int u = connection[0], v = connection[1];
            adj[u].emplace_back(v, 0);
            adj[v].emplace_back(u, 1);
        }

        nodes.emplace(0);
        visited[0] = true;

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();

            for (const auto& [value, dir] : adj[front]) {
                if (!visited[value]) {
                    visited[value] = true;

                    if (dir == 0)
                        count += 1;
                    nodes.emplace(value);
                }
            }
        }

        return count;
    }
};