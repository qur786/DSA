class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n), blueAdj(n);
        queue<tuple<int, int, int>> nodes;
        vector<int> distances(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));

        for (const auto& edge : redEdges) {
            int x = edge[0], y = edge[1];
            redAdj[x].push_back(y);
        }
        for (const auto& edge : blueEdges) {
            int x = edge[0], y = edge[1];
            blueAdj[x].push_back(y);
        }

        nodes.emplace(0, 0, 0);
        nodes.emplace(0, 1, 0);

        visited[0][0] = true;
        visited[0][1] = true;
        distances[0] = 0;

        while (!nodes.empty()) {
            auto [pos, color, distance] = nodes.front();
            nodes.pop();

            const auto adj = color ? blueAdj : redAdj;
            const int currentColor = !color;
            const int newDistance = distance + 1;

            for (const auto& node : adj[pos]) {
                if (!visited[node][currentColor]) {
                    visited[node][currentColor] = true;
                    distances[node] =
                        distances[node] == -1 ? newDistance : distances[node];
                    nodes.emplace(node, currentColor, newDistance);
                }
            }
        }

        return distances;
    }
};