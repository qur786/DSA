class Solution {
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<pair<int, int>> nodes;
        vector<vector<int>> distance(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!mat[i][j]) {
                    nodes.emplace(i, j);
                }
            }
        }

        int dist = 0;

        while (!nodes.empty()) {
            dist++;
            int size = nodes.size();

            for (int i = 0; i < size; i++) {

                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        mat[adjX][adjY]) {
                        distance[adjX][adjY] = dist;
                        mat[adjX][adjY] = 0;
                        nodes.emplace(adjX, adjY);
                    }
                }
            }
        }

        return distance;
    }
};