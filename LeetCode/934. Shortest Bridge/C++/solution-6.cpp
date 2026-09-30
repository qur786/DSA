class Solution {
private:
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> nodes, edgeNodes;
        bool found = false;

        for (int i = 0; i < rows && !found; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    nodes.emplace(i, j);
                    grid[i][j] = 2;
                    found = true;
                    break;
                }
            }
        }

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();
            bool isEdgeNode = false;
            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                    if (grid[adjX][adjY] == 1) {
                        nodes.emplace(adjX, adjY);
                        grid[adjX][adjY] = 2;
                    } else if (grid[adjX][adjY] == 0)
                        isEdgeNode = true;
                } else
                    isEdgeNode = true;
            }
            if (isEdgeNode)
                edgeNodes.emplace(x, y);
        }

        int distance = -1;

        while (!edgeNodes.empty()) {
            int size = edgeNodes.size();
            distance++;

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
                            edgeNodes.emplace(adjX, adjY);
                            grid[adjX][adjY] = 2;
                        }
                    }
                }
            }
        }

        return distance;
    }
};