class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        int eX = entrance[0], eY = entrance[1];

        if (maze[eX][eY] == '+')
            return -1;

        const int rowD[4] = {0, 0, 1, -1};
        const int colD[4] = {1, -1, 0, 0};
        queue<pair<int, int>> nodes;

        nodes.emplace(eX, eY);
        maze[eX][eY] = '+';
        int distance = -1;

        while (!nodes.empty()) {
            int size = nodes.size();
            distance++;

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
                    } else if (x != eX || y != eY)
                        return distance;
                }
            }
        }

        return -1;
    }
};