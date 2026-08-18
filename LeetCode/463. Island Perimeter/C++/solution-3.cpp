class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        const int rowD[4] = {1, -1, 0, 0};
        const int colD[4] = {0, 0, 1, -1};
        int perimeter = 0;
        queue<pair<int, int>> nodes;
        bool found = false;

        for (int i = 0; i < rows && !found; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j]) {
                    grid[i][j] = -1;
                    nodes.emplace(i, j);
                    found = true;
                    break;
                }

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                    if (grid[adjX][adjY] == 0)
                        perimeter++;
                    else if (grid[adjX][adjY] == 1) {
                        grid[adjX][adjY] = -1;
                        nodes.emplace(adjX, adjY);
                    }
                } else
                    perimeter++;
            }
        }

        return perimeter;
    }
};