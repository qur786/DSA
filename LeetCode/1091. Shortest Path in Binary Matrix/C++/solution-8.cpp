class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (grid[0][0])
            return -1;
        if (rows == 1 && cols == 1)
            return 1;
        const int rowD[8] = {0, 0, 1, -1, 1, 1, -1, -1};
        const int colD[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        queue<pair<int, int>> nodes;

        nodes.emplace(0, 0);
        grid[0][0] = 1;
        int distance = 1;

        while (!nodes.empty()) {
            int size = nodes.size();
            distance++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();
                for (int d = 0; d < 8; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (adjX == rows - 1 && adjY == cols - 1 &&
                        !grid[adjX][adjY])
                        return distance;

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        !grid[adjX][adjY]) {
                        grid[adjX][adjY] = 1;
                        nodes.emplace(adjX, adjY);
                    }
                }
            }
        }

        return -1;
    }
};