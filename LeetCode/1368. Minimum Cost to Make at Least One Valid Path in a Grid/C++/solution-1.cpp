class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));
        deque<pair<int, int>> nodes;
        nodes.emplace_back(0, 0);
        cost[0][0] = 0;

        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        while (!nodes.empty()) {
            auto [x, y] = nodes.front();
            nodes.pop_front();

            if (x == rows - 1 && y == cols - 1)
                return cost[x][y];

            for (int d = 0; d < 4; d++) {
                int adjX = x + rowD[d];
                int adjY = y + colD[d];

                if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                    int c = grid[x][y] != (d + 1);

                    if ((cost[x][y] + c) < cost[adjX][adjY]) {
                        cost[adjX][adjY] = cost[x][y] + c;
                        if (c)
                            nodes.emplace_back(adjX, adjY);
                        else
                            nodes.emplace_front(adjX, adjY);
                    }
                }
            }
        }

        return cost[rows - 1][cols - 1];
    }
};