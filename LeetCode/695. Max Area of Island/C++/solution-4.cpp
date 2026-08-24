class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, rows = grid.size(), cols = grid[0].size();

        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        queue<pair<int, int>> nodes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    int area = 1;
                    nodes.emplace(i, j);

                    while (!nodes.empty()) {
                        auto [x, y] = nodes.front();
                        nodes.pop();

                        for (int d = 0; d < 4; d++) {
                            int adjX = x + rowD[d];
                            int adjY = y + colD[d];

                            if (0 <= adjX && adjX < rows && 0 <= adjY &&
                                adjY < cols && grid[adjX][adjY]) {
                                area += 1;
                                grid[adjX][adjY] = 0;
                                nodes.emplace(adjX, adjY);
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};