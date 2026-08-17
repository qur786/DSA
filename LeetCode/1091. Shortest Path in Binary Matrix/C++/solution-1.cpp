class Solution {
private:
    int directions[8][2] = {
        {1, 0},   // right
        {-1, 0},  // left
        {0, 1},   // up
        {0, -1},  // down
        {-1, -1}, // left-up
        {1, 1},   // right-down
        {-1, 1},  // left-down
        {1, -1},  // right-up
    };
    bool isValidPos(int x, int y, int rows, int cols) {
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[0][0] || grid[rows - 1][cols - 1])
            return -1;

        queue<tuple<int, int, int>> nodes; // x, y, distance;

        nodes.push({0, 0, 1});

        while (!nodes.empty()) {
            const auto [x, y, distance] = nodes.front();
            nodes.pop();

            if (x == rows - 1 && y == cols - 1)
                return distance;

            for (const auto& dir : directions) {
                int adjX = x + dir[0];
                int adjY = y + dir[1];

                if (this->isValidPos(adjX, adjY, rows, cols) &&
                    !grid[adjX][adjY]) {

                    grid[adjX][adjY] = 1;
                    nodes.push({adjX, adjY, distance + 1});
                }
            }
        }

        return -1;
    }
};