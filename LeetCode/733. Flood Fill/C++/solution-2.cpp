class Solution {
private:
    const int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    bool isValidPosition(int x, int y, int rowCount, int colCount) {
        return (0 <= x && x < rowCount) && (0 <= y && y < colCount);
    }

public:
    vector<vector<int>>& floodFill(vector<vector<int>>& image, int sr, int sc,
                                   int color) {

        int rowCount = image.size(), colCount = image[0].size();
        if (!rowCount && !colCount)
            return image;

        int matchedColor = image[sr][sc];
        if (matchedColor == color)
            return image;

        queue<pair<int, int>> nodes;
        nodes.push({sr, sc});

        image[sr][sc] = color;

        while (!nodes.empty()) {
            auto [r, c] = nodes.front();
            nodes.pop();

            for (const auto& dir : this->directions) {
                int adjacentR = r + dir[0];
                int adjacentC = c + dir[1];
                if (!this->isValidPosition(adjacentR, adjacentC, rowCount,
                                           colCount))
                    continue;
                if (image[adjacentR][adjacentC] == matchedColor) {
                    image[adjacentR][adjacentC] = color;
                    nodes.push({adjacentR, adjacentC});
                }
            }
        }

        return image;
    }
};