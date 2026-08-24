class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};

        queue<pair<int, int>> nodes;

        nodes.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';

        int steps = -1;

        while (!nodes.empty()) {
            steps++;
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = nodes.front();
                nodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjX = x + rowD[d];
                    int adjY = y + colD[d];

                    if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols) {
                        if (maze[adjX][adjY] == '.') {
                            maze[adjX][adjY] = '+';
                            nodes.emplace(adjX, adjY);
                        }
                    } else if (x != entrance[0] || y != entrance[1])
                        return steps;
                }
            }
        }

        return -1;
    }
};