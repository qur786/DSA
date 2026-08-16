class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<bool>> visited(
            n, vector<bool>(
                   2, false)); // 0 => index, 1 => color (0 -> blue, 1 -> red)
        queue<tuple<int, int, int>>
            nodes; // 0 => index, 1 => color, 2 => distance travelled
        nodes.push({0, 0, 0});
        nodes.push({0, 1, 0});

        vector<vector<int>> redAdj(n), blueAdj(n);
        vector<int> answer(n, -1);
        answer[0] = 0;

        for (const auto& redEdge : redEdges) {
            redAdj[redEdge[0]].push_back(redEdge[1]);
        }
        for (const auto& blueEdge : blueEdges) {
            blueAdj[blueEdge[0]].push_back(blueEdge[1]);
        }

        while (!nodes.empty()) {
            auto [node, color, distance] = nodes.front();
            nodes.pop();
            int nextColor = !color;
            auto neighbors = color ? redAdj[node] : blueAdj[node];

            for (const int n : neighbors) {
                if (!visited[n][nextColor]) {
                    visited[n][nextColor] = true;
                    nodes.push({n, nextColor, distance + 1});
                }
                answer[n] = answer[n] == -1 ? distance + 1 : answer[n];
            }
        }

        return answer;
    }
};