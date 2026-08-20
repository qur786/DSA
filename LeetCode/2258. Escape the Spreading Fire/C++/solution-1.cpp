class Solution {
private:
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};
    vector<vector<int>> fireDurations;
    int calculateFireDurations(vector<vector<int>>& grid, int rows, int cols) {
        queue<pair<int, int>> nodes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    nodes.emplace(i, j);
                    this->fireDurations[i][j] = 0;
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
                    int adjX = x + this->rowD[d];
                    int adjY = y + this->colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                        if (this->fireDurations[adjX][adjY] == 1e9 &&
                            grid[adjX][adjY] == 0) {
                            this->fireDurations[adjX][adjY] = duration;
                            nodes.emplace(adjX, adjY);
                        }
                    }
                }
            }
        }

        return duration;
    }
    bool traverse(vector<vector<int>>& grid, int rows, int cols,
                  int initialDuration) {
        if (initialDuration >= fireDurations[0][0])
            return false;
        queue<pair<int, int>> nodes;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        nodes.emplace(0, 0);
        visited[0][0] = true;
        int duration = initialDuration;
        while (!nodes.empty()) {
            int size = nodes.size();
            duration++;
            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();
                for (int d = 0; d < 4; d++) {
                    int adjX = x + this->rowD[d];
                    int adjY = y + this->colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                        !visited[adjX][adjY]) {
                        if (grid[adjX][adjY] == 0) {
                            if (adjX == rows - 1 && adjY == cols - 1 &&
                                duration <= fireDurations[adjX][adjY])
                                return true;
                            else if (duration < fireDurations[adjX][adjY]) {
                                visited[adjX][adjY] = true;
                                nodes.emplace(adjX, adjY);
                            }
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
        this->fireDurations.assign(rows, vector<int>(cols, 1e9));
        this->calculateFireDurations(grid, rows, cols);
        int maxDuration = 1e6;
        int minDuration = 0;
        int answer = -1;

        while (minDuration <= maxDuration) {
            int mid = minDuration + (maxDuration - minDuration) / 2;
            if (this->traverse(grid, rows, cols, mid)) {
                answer = mid;
                minDuration = mid + 1;
            } else {
                maxDuration = mid - 1;
            }
        }

        return answer == 1e6 ? 1e9 : answer;
    }
};