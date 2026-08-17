class Solution {
private:
    bool isValidPos(int x, int y, int rows, int cols) {
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};
        queue<tuple<int, int, int>> nodes; // x, y, distance
        int startR = entrance[0], startC = entrance[1];
        nodes.push({startR, startC, 0});
        maze[startR][startC] = '+';

        while (!nodes.empty()) {
            auto [r, c, distance] = nodes.front();
            nodes.pop();

            for (int d = 0; d < 4; d++) {
                int adjR = r + rowD[d];
                int adjC = c + colD[d];

                if (this->isValidPos(adjR, adjC, rows, cols)) {
                    if (maze[adjR][adjC] == '.') {
                        maze[adjR][adjC] = '+';
                        nodes.push({adjR, adjC, distance + 1});
                    }
                } else if (distance > 0)
                    return distance;
            }
        }

        return -1;
    }
};