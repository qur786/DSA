class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 9, col = 9;

        vector<vector<int>> rowMap(row, vector<int>(col, -1)),
            colMap(col, vector<int>(row, -1)),
            boxMap(row, vector<int>(col, -1));

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (board[r][c] == '.')
                    continue;
                int value = board[r][c] - '1';

                int boxRow = (r / 3) * 3 + c / 3;

                if (rowMap[r][value] != -1 || colMap[c][value] != -1 ||
                    boxMap[boxRow][value] != -1)
                    return false;

                rowMap[r][value] = value;
                colMap[c][value] = value;
                boxMap[boxRow][value] = value;
            }
        }

        return true;
    }
};