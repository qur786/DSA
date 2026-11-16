class Solution {
private:
    bool solve(vector<vector<char>>& board, vector<pair<int, int>>& emptyCells,
               int* rows, int* cols, int* box, int index, int n) {
        if (index == emptyCells.size())
            return true;

        auto [x, y] = emptyCells[index];

        int boxCell = (x / 3) * 3 + y / 3;

        for (int i = 1; i <= 9; i++) {
            int bit = 1 << i;
            int used = rows[x] | cols[y] | box[boxCell];
            if (bit & used)
                continue;
            rows[x] |= bit;
            cols[y] |= bit;
            box[boxCell] |= bit;
            board[x][y] = i + '0';
            if (solve(board, emptyCells, rows, cols, box, index + 1, n))
                return true;
            rows[x] ^= bit;
            cols[y] ^= bit;
            box[boxCell] ^= bit;
            board[x][y] = '.';
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, box[9] = {0};
        vector<pair<int, int>> emptyCells;
        int n = 9;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    emptyCells.emplace_back(i, j);
                else {
                    int val = board[i][j] - '0';
                    int bit = 1 << val;
                    rows[i] |= bit;
                    cols[j] |= bit;
                    box[(i / 3) * 3 + j / 3] |= bit;
                }
            }
        }

        solve(board, emptyCells, rows, cols, box, 0, n);
    }
};