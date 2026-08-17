class Solution {
private:
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    bool isValidPosition(int x, int y, int rowCount, int colCount) {
        return (0 <= x && x < rowCount) && (0 <= y && y < colCount);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int rowCount = image.size(), colCount = image[0].size();
        if (!rowCount && !colCount)
            return {};
        vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
        queue<pair<int, int>> nodes;
        nodes.push({sr, sc});
        visited[sr][sc] = true;
        int matchedColor = image[sr][sc];

        while (!nodes.empty()) {
            auto [r, c] = nodes.front();
            nodes.pop();

            for (const auto& dir : this->directions) {
                int adjacentR = r + dir[0], adjacentC = c + dir[1];
                if (!this->isValidPosition(adjacentR, adjacentC, rowCount,
                                           colCount))
                    continue;
                if (image[adjacentR][adjacentC] == matchedColor &&
                    !visited[adjacentR][adjacentC]) {
                    nodes.push({adjacentR, adjacentC});
                    visited[adjacentR][adjacentC] = true;
                }
            }

            image[r][c] = color;
        }

        return image;
    }
};