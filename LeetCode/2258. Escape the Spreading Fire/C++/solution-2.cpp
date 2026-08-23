class Solution {
private:
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};
    bool checkReachingEnd(vector<vector<int>>& fireMinutes,
                          vector<vector<int>>& grid, int minute) {
        int rows = fireMinutes.size(), cols = fireMinutes[0].size();
        queue<pair<int, int>> nodes;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        nodes.emplace(0, 0);
        int minutes = minute;
        visited[0][0] = true;
        while (!nodes.empty()) {
            int size = nodes.size();
            minutes++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        grid[adjX][adjY] == 0 && !visited[adjX][adjY]) {
                        if (adjX == rows - 1 && adjY == cols - 1 &&
                            fireMinutes[adjX][adjY] >= minutes)
                            return true;
                        else if (minutes < fireMinutes[adjX][adjY]) {
                            visited[adjX][adjY] = true;
                            nodes.emplace(adjX, adjY);
                        }
                    }
                }
            }
        }
        return false;
    }

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (rows == 1 && cols == 1)
            return 0;
        vector<vector<int>> fireMinutes(rows, vector<int>(cols, 1e9));
        queue<pair<int, int>> nodes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    nodes.emplace(i, j);
                    fireMinutes[i][j] = 0;
                }
            }
        }

        int minutes = 0;

        while (!nodes.empty()) {
            int size = nodes.size();
            minutes++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        fireMinutes[adjX][adjY] == 1e9 &&
                        grid[adjX][adjY] == 0) {
                        fireMinutes[adjX][adjY] = minutes;
                        nodes.emplace(adjX, adjY);
                    }
                }
            }
        }

        int low = 0, high = 1e6;
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid >= fireMinutes[0][0]) {
                high = mid - 1;
                continue;
            }

            if (checkReachingEnd(fireMinutes, grid, mid)) {
                answer = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return answer == 1e6 ? 1e9 : answer;
    }
};