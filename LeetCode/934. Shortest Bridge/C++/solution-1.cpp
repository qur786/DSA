class Solution {
private:
    queue<pair<int, int>> edgeNodes;
    const int rowD[4] = {0, 0, 1, -1};
    const int colD[4] = {1, -1, 0, 0};
    bool isValidPositions(int x, int y, int rows, int cols) {
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }
    void getFirstLandEdgeNodes(vector<vector<int>>& grid, int x, int y,
                               int rows, int cols) {
        queue<pair<int, int>> nodes;
        nodes.push({x, y});

        while (!nodes.empty()) {
            auto [r, c] = nodes.front();
            nodes.pop();
            bool isEdge = false;
            for (int d = 0; d < 4; d++) {
                int adjR = r + this->rowD[d];
                int adjC = c + this->colD[d];

                if (this->isValidPositions(adjR, adjC, rows, cols)) {
                    if (grid[adjR][adjC] == 1) {
                        grid[adjR][adjC] = 2;
                        nodes.push({adjR, adjC});
                    } else if (grid[adjR][adjC] == 0)
                        isEdge = true;
                }
            }
            this->edgeNodes.emplace(r, c);
        }
    }

    int getMinDistanceBetweenLands(vector<vector<int>>& grid, int rows,
                                   int cols) {
        int distance = 0;
        while (!this->edgeNodes.empty()) {
            int size = this->edgeNodes.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = this->edgeNodes.front();
                this->edgeNodes.pop();

                for (int d = 0; d < 4; d++) {
                    int adjR = r + this->rowD[d];
                    int adjC = c + this->colD[d];

                    if (this->isValidPositions(adjR, adjC, rows, cols) &&
                        grid[adjR][adjC] != 2) {
                        if (grid[adjR][adjC] == 1)
                            return distance;
                        grid[adjR][adjC] = 2;
                        this->edgeNodes.emplace(adjR, adjC);
                    }
                }
            }
            distance++;
        }

        return distance;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        bool firstLandFound = false;
        for (int i = 0; i < rows && !firstLandFound; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    this->getFirstLandEdgeNodes(grid, i, j, rows, cols);
                    firstLandFound = true;
                    break;
                }
            }
        }

        int minDistance = this->getMinDistanceBetweenLands(grid, rows, cols);

        return minDistance;
    }
};