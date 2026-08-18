class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int freshOranges = 0;
        const int rowD[4] = {1, -1, 0, 0};
        const int colD[4] = {0, 0, 1, -1};
        queue<pair<int, int>> rottenOranges;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    rottenOranges.emplace(i, j);
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        if (!freshOranges)
            return 0;

        int minutes = 0;

        while (!rottenOranges.empty()) {
            int size = rottenOranges.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = rottenOranges.front();
                rottenOranges.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                        if (grid[adjX][adjY] == 1) {
                            freshOranges--;
                            grid[adjX][adjY] = 2;
                            rottenOranges.emplace(adjX, adjY);
                        }
                    }
                }
            }
            minutes++;
            if (freshOranges == 0)
                break;
        }

        return freshOranges ? -1 : minutes;
    }
};