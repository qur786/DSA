class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> nodes;
        nodes.push(0);
        vector<vector<pair<int, int>>> adj(n);
        int reorder = 0;

        for (const auto& connection : connections) {
            int x = connection[0], y = connection[1];
            adj[x].emplace_back(y, 1);
            adj[y].emplace_back(x, 0);
        }

        while (!nodes.empty()) {
            int pos = nodes.front();
            nodes.pop();

            for (auto& [x, dir] : adj[pos])
                if (!visited[x]) {
                    visited[x] = true;
                    nodes.push(x);
                    if (dir)
                        reorder++;
                }
        }

        return reorder;
    }
};