class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        if (rows == 0 && cols == 0)
            return 0;
        if (rows == 1 && cols == 1)
            return grid[0][0];

        deque<tuple<int, int, int>> nodes;
        nodes.emplace_back(0, 0, grid[0][0]);
        visited[0][0] = true;

        while (!nodes.empty()) {
            auto [x, y, obCount] = nodes.front();
            nodes.pop_front();

            if (x == rows - 1 && y == cols - 1)
                return obCount;

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                    !visited[adjX][adjY]) {
                    visited[adjX][adjY] = true;
                    if (grid[adjX][adjY]) {
                        nodes.emplace_back(adjX, adjY, obCount + 1);
                    } else {
                        nodes.emplace_front(adjX, adjY, obCount);
                    }
                }
            }
        }
        return -1;
    }
};