class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<int> answer(n, INT_MAX);
        vector<vector<int>> blueGraph(n, vector<int>()),
            redGraph(n, vector<int>());

        for (const auto& edge : redEdges) {
            redGraph[edge[0]].push_back(edge[1]);
        }
        for (const auto& edge : blueEdges) {
            blueGraph[edge[0]].push_back(edge[1]);
        }

        queue<tuple<int, int, int>> nodes; // node, color, distance
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        nodes.push({0, 0, 0});             // Red
        nodes.push({0, 1, 0});             // Blue
        answer[0] = 0;
        visited[0] = {false, false};

        while (!nodes.empty()) {
            auto [node, color, distance] = nodes.front();
            nodes.pop();
            int redGraphSize = redGraph[node].size();
            int blueGraphSize = blueGraph[node].size();

            if (color == 1)
                for (int i = 0; i < redGraphSize; i++) {
                    int value = redGraph[node][i];
                    if (visited[value][!color])
                        continue;
                    answer[value] = min(answer[value], distance + 1);
                    visited[value][!color] = true;
                    nodes.push({value, !color, distance + 1});
                }

            if (color == 0)
                for (int i = 0; i < blueGraphSize; i++) {
                    int value = blueGraph[node][i];
                    if (visited[value][!color])
                        continue;
                    answer[value] = min(answer[value], distance + 1);

                    visited[value][!color] = true;
                    nodes.push({value, !color, distance + 1});
                }
        }

        for (int i = 0; i < n; i++)
            answer[i] = answer[i] == INT_MAX ? -1 : answer[i];

        return answer;
    }
};