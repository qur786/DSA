class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, -1)),
            cols(9, vector<int>(9, -1)), box(9, vector<int>(9, -1));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int value = board[i][j] - '1';

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rows[i][value] != -1 || cols[j][value] != -1 ||
                    box[boxIndex][value] != -1)
                    return false;
                rows[i][value] = value;
                cols[j][value] = value;
                box[boxIndex][value] = value;
            }
        }

        return true;
    }
};