class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> answer(n, INT_MAX);
        vector<vector<int>> redAdj(n), blueAdj(n);
        queue<tuple<int, int, int>> nodes;
        nodes.emplace(0, 0, 0); // blue;
        nodes.emplace(0, 0, 1); // red;
        visited[0][0] = true;
        visited[0][1] = true;
        answer[0] = 0;

        for (const auto& connection : redEdges) {
            redAdj[connection[0]].push_back(connection[1]);
        }

        for (const auto& connection : blueEdges) {
            blueAdj[connection[0]].push_back(connection[1]);
        }

        while (!nodes.empty()) {
            auto [value, distance, color] = nodes.front();
            nodes.pop();

            int newColor = !color;
            int newDistance = distance + 1;
            auto adj = color ? blueAdj : redAdj;

            for (const auto& v : adj[value]) {
                if (!visited[v][newColor]) {
                    visited[v][newColor] = true;
                    answer[v] = min(newDistance, answer[v]);
                    nodes.emplace(v, newDistance, newColor);
                }
            }
        }

        for (int& v : answer) {
            if (v == INT_MAX)
                v = -1;
        }

        return answer;
    }
};