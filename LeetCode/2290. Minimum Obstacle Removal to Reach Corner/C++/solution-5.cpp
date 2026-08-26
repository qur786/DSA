class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (rows == 1 && cols == 1)
            return grid[0][0];
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};
        deque<pair<int, int>> nodes;
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        nodes.emplace_back(0, 0);
        dist[0][0] = grid[0][0];

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop_front();

            if (x == rows - 1 && y == cols - 1)
                dist[x][y];

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                    int cost = grid[adjX][adjY];
                    if (dist[x][y] + cost < dist[adjX][adjY]) {
                        dist[adjX][adjY] = dist[x][y] + cost;
                        if (cost)
                            nodes.emplace_back(adjX, adjY);
                        else
                            nodes.emplace_front(adjX, adjY);
                    }
                }
            }
        }
        return dist[rows - 1][cols - 1];
    }
};