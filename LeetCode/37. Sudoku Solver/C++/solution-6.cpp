class Solution {
private:
    bool solve(vector<vector<char>>& board, vector<pair<int, int>>& emptyCells,
               int* rows, int* cols, int* box, int n, int index) {
        if (index == emptyCells.size())
            return true;

        auto [x, y] = emptyCells[index];

        int boxNo = 3 * (x / 3) + y / 3;
        int used = rows[x] | cols[y] | box[boxNo];

        for (int val = 1; val <= 9; val++) {
            int bit = 1 << val;

            if (used & bit)
                continue;
            board[x][y] = val + '0';
            rows[x] |= bit;
            cols[y] |= bit;
            box[boxNo] |= bit;
            if (solve(board, emptyCells, rows, cols, box, n, index + 1))
                return true;
            rows[x] ^= bit;
            cols[y] ^= bit;
            box[boxNo] ^= bit;
            board[x][y] = '.';
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
                    int boxNo = 3 * (i / 3) + j / 3;

                    rows[i] |= bit;
                    cols[j] |= bit;
                    box[boxNo] |= bit;
                }
            }
        }

        solve(board, emptyCells, rows, cols, box, n, 0);
    }
};