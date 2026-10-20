class Solution {
private:
    static constexpr int rowD[4] = {0, 0, 1, -1};
    static constexpr int colD[4] = {1, -1, 0, 0};
    bool solve(vector<vector<char>>& board, const string& word, int x, int y,
               int rows, int cols, int index) {
        if (index == word.size())
            return true;

        for (int d = 0; d < 4; d++) {
            int adjX = x + rowD[d];
            int adjY = y + colD[d];

            if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                board[adjX][adjY] == word[index]) {
                char ch = board[adjX][adjY];
                board[adjX][adjY] = '#';
                if (solve(board, word, adjX, adjY, rows, cols, index + 1))
                    return true;
                board[adjX][adjY] = ch;
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    char ch = board[i][j];
                    board[i][j] = '#';
                    if (solve(board, word, i, j, rows, cols, 1))
                        return true;
                    board[i][j] = ch;
                }
            }
        }

        return false;
    }
};