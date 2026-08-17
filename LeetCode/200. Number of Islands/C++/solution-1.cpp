class Solution {
private:
    const int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    bool isValidPos(int x, int y, int rows, int cols) const {
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }
    void processLand(vector<vector<char>>& grid, int x, int y) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> nodes;
        nodes.push({x, y});

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for (const auto& dir : directions) {
                int adjX = x + dir[0];
                int adjY = y + dir[1];

                if (this->isValidPos(adjX, adjY, rows, cols) &&
                    grid[adjX][adjY] == '1') {
                    grid[adjX][adjY] = '0';
                    nodes.push({adjX, adjY});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int noOfIslands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    this->processLand(grid, i, j);
                    grid[i][j] = '0';
                    noOfIslands += 1;
                }
            }
        }

        return noOfIslands;
    }
};