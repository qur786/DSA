class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        queue<pair<int, int>> nodes;
        vector<vector<int>> answer(rows, vector<int>(cols, 0));
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isWater[i][j])
                    nodes.emplace(i, j);
            }
        }

        int height = 1;
        while (!nodes.empty()) {
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                        if (!isWater[adjX][adjY]) {
                            isWater[adjX][adjY] = 1;
                            answer[adjX][adjY] = height;
                            nodes.emplace(adjX, adjY);
                        }
                    }
                }
            }
            height++;
        }

        return answer;
    }
};