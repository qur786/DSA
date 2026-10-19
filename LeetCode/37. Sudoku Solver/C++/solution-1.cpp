class Solution {
private:
    bool solveSudo(vector<vector<char>>& board, int row, int col, int rows,
                   int cols, vector<vector<bool>>& visitedC,
                   vector<vector<bool>>& visitedR,
                   vector<vector<bool>>& visited) {
        if (row == rows) {
            return true;
        }
        if (col == cols) {
            return solveSudo(board, row + 1, 0, rows, cols, visitedC, visitedR,
                             visited);
        }

        if (board[row][col] != '.')
            return solveSudo(board, row, col + 1, rows, cols, visitedC,
                             visitedR, visited);

        for (int val = 0; val < 9; val++) {
            int boxR = 3 * (row / 3) + col / 3;
            if (visitedR[row][val] || visitedC[col][val] || visited[boxR][val])
                continue;
            visitedR[row][val] = visitedC[col][val] = visited[boxR][val] = true;
            board[row][col] = '1' + val;
            if (solveSudo(board, row, col + 1, rows, cols, visitedC, visitedR,
                          visited)) {
                return true;
            }
            board[row][col] = '.';
            visitedR[row][val] = visitedC[col][val] = visited[boxR][val] =
                false;
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> visited(9, vector<bool>(9, false)),
            visitedC(9, vector<bool>(9, false)),
            visitedR(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    visited[3 * (i / 3) + (j / 3)][index] = true;
                    visitedC[j][index] = true;
                    visitedR[i][index] = true;
                }
            }
        }
        solveSudo(board, 0, 0, 9, 9, visitedC, visitedR, visited);
    }
};