class Solution {
private:
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};
    vector<vector<int>> fireMinutes;
    bool canTraverse(vector<vector<int>>& grid, int start, int rows, int cols) {
        if (fireMinutes[0][0] <= start)
            return false;
        queue<pair<int, int>> nodes;
        nodes.emplace(0, 0);
        int duration = start;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;

        while (!nodes.empty()) {
            int size = nodes.size();
            duration++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (adjX == rows - 1 && adjY == cols - 1)
                        return fireMinutes[adjX][adjY] >= duration;

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        !visited[adjX][adjY] && !grid[adjX][adjY] &&
                        duration < fireMinutes[adjX][adjY]) {
                        nodes.emplace(adjX, adjY);
                        visited[adjX][adjY] = true;
                    }
                }
            }
        }

        return false;
    }
    void calculateFireMinutes(vector<vector<int>>& grid, int rows, int cols) {
        fireMinutes.assign(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> nodes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    nodes.emplace(i, j);
                    fireMinutes[i][j] = 0;
                }
            }
        }

        int duration = 0;

        while (!nodes.empty()) {
            int size = nodes.size();
            duration++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        grid[adjX][adjY] == 0 &&
                        fireMinutes[adjX][adjY] == INT_MAX) {
                        fireMinutes[adjX][adjY] = duration;
                        nodes.emplace(adjX, adjY);
                    }
                }
            }
        }
    }

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (rows == 0 && cols == 0 || rows == 1 && cols == 1)
            return 1e9;

        calculateFireMinutes(grid, rows, cols);

        int low = 0, high = 1e9, answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canTraverse(grid, mid, rows, cols)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};