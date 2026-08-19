class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        deque<tuple<int, int, int>> nodes;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        nodes.emplace_back(0, 0, grid[0][0]);
        visited[0][0] = true;
        const int rowD[4] = {1, -1, 0, 0};
        const int colD[4] = {0, 0, 1, -1};
        int minObstacles = INT_MAX;

        while (!nodes.empty()) {
            auto [x, y, obstacles] = nodes.front();
            nodes.pop_front();

            if (x == rows - 1 && y == cols - 1)
                minObstacles = min(minObstacles, obstacles);

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                    !visited[adjX][adjY]) {
                    visited[adjX][adjY] = true;
                    if (grid[adjX][adjY])
                        nodes.emplace_back(adjX, adjY, obstacles + 1);
                    else
                        nodes.emplace_front(adjX, adjY, obstacles);
                }
            }
        }

        return minObstacles;
    }
};