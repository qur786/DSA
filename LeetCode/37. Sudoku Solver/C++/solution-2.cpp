class Solution {
private:
    bool solveSudo(vector<vector<char>>& board, int row, int col, int rows,
                   int cols, int visitedC[], int visitedR[], int visited[]) {
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
            if (solveSudo(board, row, col + 1, rows, cols, visitedC, visitedR,
                          visited)) {
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

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int shift = board[i][j] - '0';
                    int bit = 1 << shift;
                    int boxR = 3 * (i / 3) + (j / 3);
                    visited[boxR] |= bit;
                    visitedC[j] |= bit;
                    visitedR[i] |= bit;
                }
            }
        }
        solveSudo(board, 0, 0, 9, 9, visitedC, visitedR, visited);
    }
};