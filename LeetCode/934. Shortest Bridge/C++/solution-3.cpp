class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> nodes, edgeNodes;

        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};
        bool found = false;

        for (int i = 0; i < rows && !found; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    nodes.emplace(i, j);
                    grid[i][j] = -1;

                    while (!nodes.empty()) {
                        auto [x, y] = nodes.front();
                        nodes.pop();
                        bool isEdge = false;

                        for (int d = 0; d < 4; d++) {
                            int adjX = x + rowD[d];
                            int adjY = y + colD[d];

                            if (0 <= adjX && adjX < rows && 0 <= adjY &&
                                adjY < cols) {
                                if (grid[adjX][adjY] == 1) {
                                    grid[adjX][adjY] = -1;
                                    nodes.emplace(adjX, adjY);
                                } else if (grid[adjX][adjY] == 0)
                                    isEdge = true;
                            } else
                                isEdge = true;
                        }
                        edgeNodes.emplace(x, y);
                    }
                    found = true;
                    break;
                }
            }
        }

        int distance = -1;

        while (!edgeNodes.empty()) {
            distance++;
            int size = edgeNodes.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = edgeNodes.front();
                edgeNodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                        if (grid[adjX][adjY] == 1)
                            return distance;
                        else if (grid[adjX][adjY] == 0) {
                            grid[adjX][adjY] = -1;
                            edgeNodes.emplace(adjX, adjY);
                        }
                    }
                }
            }
        }

        return -1;
    }
};