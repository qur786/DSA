class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        queue<tuple<int, int, int>> nodes;
        nodes.push({0, 0, 0}); // 0 -> blue
        nodes.push({0, 1, 0}); // 1 -> red;
        vector<int> answer(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        answer[0] = 0;
        visited[0][0] = true;
        visited[0][1] = true;

        vector<vector<int>> redAdj(n), blueAdj(n);

        for (const auto edge : redEdges)
            redAdj[edge[0]].push_back(edge[1]);
        for (const auto edge : blueEdges)
            blueAdj[edge[0]].push_back(edge[1]);

        while (!nodes.empty()) {
            auto [x, color, distance] = nodes.front();
            nodes.pop();

            auto adj = color ? blueAdj : redAdj;
            int newColor = color ? 0 : 1;
            int newDistance = distance + 1;

            for (auto const node : adj[x]) {
                if (visited[node][newColor])
                    continue;
                visited[node][newColor] = true;
                answer[node] = answer[node] == -1 ? newDistance : answer[node];
                nodes.emplace(node, newColor, newDistance);
            }
        }

        return answer;
    }
};