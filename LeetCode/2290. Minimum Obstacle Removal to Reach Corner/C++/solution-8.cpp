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
            const auto [x, y, c] = nodes.front();
            nodes.pop_front();

            if (x == rows - 1 && y == cols - 1)
                return c;

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                    !visited[adjX][adjY]) {
                    visited[adjX][adjY] = true;
                    if (grid[adjX][adjY])
                        nodes.emplace_back(adjX, adjY, c + 1);
                    else
                        nodes.emplace_front(adjX, adjY, c);
                }
            }
        }

        return 0;
    }
};