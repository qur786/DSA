class Solution {
private:
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> nodes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    nodes.emplace(i, j);
                else if (grid[i][j] == 1)
                    fresh += 1;
            }
        }

        if (fresh == 0)
            return 0;
        if (nodes.empty())
            return -1;

        int minutes = -1;

        while (!nodes.empty()) {
            int size = nodes.size();
            minutes += 1;

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        grid[adjX][adjY] == 1) {
                        fresh -= 1;
                        grid[adjX][adjY] = 2;
                        nodes.emplace(adjX, adjY);
                    }
                }
            }
        }

        return fresh ? -1 : minutes;
    }
};