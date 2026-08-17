class Solution {
private:
    int getMaxArea(vector<vector<int>>& grid, int x, int y, int rows,
                   int cols) {
        const int rowDir[4] = {0, 0, 1, -1};
        const int colDir[4] = {1, -1, 0, 0};
        int area = 1;

        queue<pair<int, int>> nodes;

        nodes.push({x, y});
        grid[x][y] = 0;

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for (int i = 0; i < 4; i++) {
                int adjX = x + rowDir[i];
                int adjY = y + colDir[i];

                if (adjX >= 0 && adjX < rows && adjY >= 0 && adjY < cols &&
                    grid[adjX][adjY]) {
                    grid[adjX][adjY] = 0;
                    area += 1;
                    nodes.emplace(adjX, adjY);
                }
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, getMaxArea(grid, i, j, rows, cols));
                }
            }
        }

        return maxArea;
    }
};