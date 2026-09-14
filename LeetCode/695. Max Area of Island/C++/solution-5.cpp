class Solution {
private:
    int getAreadOfLand(vector<vector<int>>& grid, int x, int y) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> nodes;
        nodes.emplace(x, y);
        grid[x][y] = 0;
        int area = 1;
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
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
                    maxArea = max(maxArea, getAreadOfLand(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};