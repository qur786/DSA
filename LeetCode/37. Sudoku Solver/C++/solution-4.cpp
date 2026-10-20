class Solution {
private:
    bool solve(vector<vector<char>>& board, int n, int* rows, int* cols,
               int* box, vector<pair<int, int>>& emptyCells, int index) {
        if (index == emptyCells.size())
            return true;

        auto [x, y] = emptyCells[index];
        int boxPos = 3 * (x / 3) + y / 3;
        int used = rows[x] | cols[y] | box[boxPos];

        for (int val = 1; val <= 9; val++) {
            int bit = 1 << val;
            if (used & bit)
                continue;
            board[x][y] = val + '0';
            rows[x] |= bit;
            cols[y] |= bit;
            box[boxPos] |= bit;
            if (solve(board, n, rows, cols, box, emptyCells, index + 1))
                return true;
            board[x][y] = '.';
            rows[x] ^= bit;
            cols[y] ^= bit;
            box[boxPos] ^= bit;
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        int rows[9] = {0}, cols[9] = {0}, box[9] = {0};
        vector<pair<int, int>> emptyCells;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    emptyCells.emplace_back(i, j);
                else {
                    int bit = 1 << (board[i][j] - '0');
                    rows[i] |= bit;
                    cols[j] |= bit;
                    box[3 * (i / 3) + j / 3] |= bit;
                }
            }
        }

        solve(board, n, rows, cols, box, emptyCells, 0);
    }
};