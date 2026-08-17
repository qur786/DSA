class Solution {
private:
    const int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    bool isValidPosition(int x, int y, int rows, int cols) {
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (!rows && !cols)
            return 0;

        queue<pair<int, int>> nodes;
        int landR = -1, landC = -1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    landR = i, landC = j;
                    break;
                }
            }
            if (landR != -1)
                break;
        }
        if (landR == -1)
            return 0;

        nodes.push({landR, landC});
        grid[landR][landC] = -1;
        int perimeter = 0;

        while (!nodes.empty()) {
            auto [r, c] = nodes.front();
            nodes.pop();

            for (const auto& dir : directions) {
                int adjacentR = r + dir[0];
                int adjacentC = c + dir[1];

                if (!this->isValidPosition(adjacentR, adjacentC, rows, cols)) {
                    perimeter += 1;
                    continue;
                }

                if (grid[adjacentR][adjacentC] == -1)
                    continue;

                if (!grid[adjacentR][adjacentC])
                    perimeter += 1;
                else {
                    nodes.push({adjacentR, adjacentC});
                    grid[adjacentR][adjacentC] = -1;
                }
            }
        }

        return perimeter;
    }
};