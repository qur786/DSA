class Solution {
private:
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        deque<tuple<int, int, int>> nodes;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;
        nodes.emplace_back(0, 0, grid[0][0]);

        while (!nodes.empty()) {
            auto [x, y, cost] = nodes.front();
            nodes.pop_front();

            if (x == rows - 1 && y == cols - 1)
                return cost;

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                    if (grid[adjX][adjY] == 0)
                        nodes.emplace_front(adjX, adjY, cost);
                    else if (grid[adjX][adjY] == 1)
                        nodes.emplace_back(adjX, adjY, cost + 1);
                    grid[adjX][adjY] = -1;
                }
            }
        }

        return 0;
    }
};