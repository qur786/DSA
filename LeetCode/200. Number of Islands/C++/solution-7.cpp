class Solution {
private:
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};
    void traverseIsland(vector<vector<char>>& grid,
                        queue<pair<int, int>>& nodes, int rows, int cols) {
        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                    grid[adjX][adjY] == '1') {
                    grid[adjX][adjY] = '0';
                    nodes.emplace(adjX, adjY);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> nodes;
        int island = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    nodes.emplace(i, j);
                    traverseIsland(grid, nodes, rows, cols);
                    island += 1;
                }
            }
        }

        return island;
    }
};