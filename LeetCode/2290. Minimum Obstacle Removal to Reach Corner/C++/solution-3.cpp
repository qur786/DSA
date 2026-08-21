class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        deque<tuple<int, int, int>> nodes;
        nodes.emplace_back(0, 0, grid[0][0]);

        while (!nodes.empty()) {
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                auto [x, y, oCount] = nodes.front();
                nodes.pop_front();
                if (x == rows - 1 && y == cols - 1)
                    return oCount;

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                        if (grid[adjX][adjY] == 1)
                            nodes.emplace_back(adjX, adjY, oCount + 1);
                        else if (grid[adjX][adjY] == 0)
                            nodes.emplace_front(adjX, adjY, oCount);
                        grid[adjX][adjY] = -1;
                    }
                }
            }
        }

        return 0;
    }
};