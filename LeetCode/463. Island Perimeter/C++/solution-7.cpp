class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int rows = grid.size(), cols = grid[0].size();
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        queue<pair<int, int>> nodes;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        bool found = false;

        for (int i = 0; i < rows && !found; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    nodes.emplace(i, j);
                    found = true;
                    visited[i][j] = true;
                    break;
                }
            }
        }

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                    if (grid[adjX][adjY] && !visited[adjX][adjY]) {
                        nodes.emplace(adjX, adjY);
                        visited[adjX][adjY] = true;
                    } else if (!grid[adjX][adjY])
                        peri++;
                } else
                    peri++;
            }
        }

        return peri;
    }
};