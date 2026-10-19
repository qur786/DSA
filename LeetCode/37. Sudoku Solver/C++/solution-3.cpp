class Solution {
private:
    bool solveSudo(vector<vector<char>>& board, int rows, int cols,
                   int visitedC[], int visitedR[], int visited[],
                   vector<pair<int, int>>& empty, int emptyIndex) {
        if (empty.size() == emptyIndex) {
            return true;
        }

        auto [row, col] = empty[emptyIndex];

        int boxR = 3 * (row / 3) + col / 3;
        int used = visitedR[row] | visitedC[col] | visited[boxR];
        for (int val = 1; val <= 9; val++) {
            int bit = 1 << val;
            if (used & bit)
                continue;
            visitedR[row] |= bit;
            visitedC[col] |= bit;
            visited[boxR] |= bit;
            board[row][col] = '0' + val;
            if (solveSudo(board, rows, cols, visitedC, visitedR, visited, empty,
                          emptyIndex + 1)) {
                return true;
            }
            board[row][col] = '.';
            visitedR[row] ^= bit;
            visitedC[col] ^= bit;
            visited[boxR] ^= bit;
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        int visitedR[9] = {0}, visitedC[9] = {0}, visited[9] = {0};
        vector<pair<int, int>> empty;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int shift = board[i][j] - '0';
                    int bit = 1 << shift;
                    int boxR = 3 * (i / 3) + (j / 3);
                    visited[boxR] |= bit;
                    visitedC[j] |= bit;
                    visitedR[i] |= bit;
                } else
                    empty.emplace_back(i, j);
            }
        }
        solveSudo(board, 9, 9, visitedC, visitedR, visited, empty, 0);
    }
};