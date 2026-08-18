class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (color == image[sr][sc])
            return image;
        int rows = image.size(), cols = image[0].size();
        queue<pair<int, int>> nodes;
        nodes.emplace(sr, sc);
        int orgColor = image[sr][sc];
        image[sr][sc] = color;

        const int rowD[4] = {1, -1, 0, 0};
        const int colD[4] = {0, 0, 1, -1};

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop();

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                    image[adjX][adjY] == orgColor) {
                    image[adjX][adjY] = color;
                    nodes.emplace(adjX, adjY);
                }
            }
        }

        return image;
    }
};