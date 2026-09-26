class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        // 0 -> red, 1 -> blue
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<tuple<int, int, int>>
            nodes; // 0 -> index, 1 -> distance, 2 -> color;
        vector<vector<int>> blueAdj(n), redAdj(n);
        vector<int> answer(n, INT_MAX);

        for (const auto& connection : redEdges) {
            int u = connection[0];
            int v = connection[1];
            redAdj[u].push_back(v);
        }
        for (const auto& connection : blueEdges) {
            int u = connection[0];
            int v = connection[1];
            blueAdj[u].push_back(v);
        }

        visited[0][0] = true;
        visited[0][1] = true;
        nodes.emplace(0, 0, 0);
        nodes.emplace(0, 0, 1);
        answer[0] = 0;

        while (!nodes.empty()) {
            auto [index, distance, color] = nodes.front();
            nodes.pop();

            const auto& adj = color == 0 ? redAdj : blueAdj;
            int newColor = color == 0 ? 1 : 0;

            for (int child : adj[index]) {
                if (!visited[child][newColor]) {
                    visited[child][newColor] = true;
                    answer[child] = min(answer[child], distance + 1);
                    nodes.emplace(child, distance + 1, newColor);
                }
            }
        }

        for (int& child : answer)
            if (child == INT_MAX)
                child = -1;

        return answer;
    }
};