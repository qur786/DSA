class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        queue<pair<int, int>> nodes;

        int perimeter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    nodes.emplace(i, j);
                    grid[i][j] = -1;

                    while (!nodes.empty()) {
                        auto [x, y] = nodes.front();
                        nodes.pop();

                        for (int d = 0; d < 4; d++) {
                            int adjX = x + rowD[d];
                            int adjY = y + colD[d];

                            if (0 <= adjX && adjX < rows && 0 <= adjY &&
                                adjY < cols) {
                                if (grid[adjX][adjY] == 1) {
                                    nodes.emplace(adjX, adjY);
                                    grid[adjX][adjY] = -1;
                                } else if (grid[adjX][adjY] == 0)
                                    perimeter++;
                            } else
                                perimeter++;
                        }
                    }

                    return perimeter;
                }
            }
        }

        return perimeter;
    }
};