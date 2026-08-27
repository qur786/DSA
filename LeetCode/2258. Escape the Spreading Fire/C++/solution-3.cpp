class Solution {
private:
    vector<vector<int>> fireMinutes;
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};
    void calculateFireMinutes(const vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
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

        int minutes = 0;

        while (!nodes.empty()) {
            minutes++;
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        grid[adjX][adjY] == 0 &&
                        fireMinutes[adjX][adjY] == INT_MAX) {
                        nodes.emplace(adjX, adjY);
                        fireMinutes[adjX][adjY] = minutes;
                    }
                }
            }
        }
    }
    bool traverse(vector<vector<int>>& grid, int startMinutes) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;
        queue<pair<int, int>> nodes;
        nodes.emplace(0, 0);

        int duration = startMinutes;

        while (!nodes.empty()) {
            duration++;
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        !visited[adjX][adjY] && grid[adjX][adjY] == 0) {
                        if (fireMinutes[adjX][adjY] >= duration && adjX == rows - 1 &&
                            adjY == cols - 1)
                            return true;
                        else if (fireMinutes[adjX][adjY] > duration) {
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
        this->calculateFireMinutes(grid);
        int low = 0, high = 1e6;
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid >= fireMinutes[0][0]) {
                high = mid - 1;
                continue;
            }

            if (this->traverse(grid, mid)) {
                answer = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return answer == 1e6 ? 1e9 : answer;
    }
};