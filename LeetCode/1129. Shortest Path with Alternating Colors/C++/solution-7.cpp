class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        // color 0 -> blue, 1 -> red
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> distances(n, INT_MAX);
        queue<tuple<int, int, int>> nodes; // value, color, distances;
        nodes.emplace(0, 0, 0);
        nodes.emplace(0, 1, 0);
        visited[0][0] = true;
        visited[0][1] = true;
        vector<vector<int>> blueAdj(n), redAdj(n);
        distances[0] = 0;

        for (const auto& edge : redEdges) {
            int u = edge[0], v = edge[1];
            redAdj[u].push_back(v);
        }
        for (const auto& edge : blueEdges) {
            int u = edge[0], v = edge[1];
            blueAdj[u].push_back(v);
        }

        while (!nodes.empty()) {
            auto [value, color, distance] = nodes.front();
            nodes.pop();
            int newColor = color == 0 ? 1 : 0;
            int newDistance = distance + 1;
            const auto& adj = color == 0 ? redAdj : blueAdj;

            for (int child : adj[value]) {
                if (!visited[child][newColor]) {
                    visited[child][newColor] = true;
                    distances[child] = min(newDistance, distances[child]);
                    nodes.emplace(child, newColor, newDistance);
                }
            }
        }

        for (int& d : distances)
            if (d == INT_MAX)
                d = -1;

        return distances;
    }
};