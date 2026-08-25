class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int fresh = 0;
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};
        queue<pair<int, int>> nodes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    nodes.emplace(i, j);
            }
        }

        if (!fresh)
            return 0;

        int time = -1;

        while (!nodes.empty()) {
            int size = nodes.size();
            time++;
            if (!fresh)
                return time;

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                        if (grid[adjX][adjY] == 1) {
                            fresh--;
                            grid[adjX][adjY] = 2;
                            nodes.emplace(adjX, adjY);
                        }
                    }
                }
            }
        }

        return -1;
    }
};