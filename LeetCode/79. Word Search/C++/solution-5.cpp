class Solution {
private:
    static constexpr int rowD[4] = {0, 0, 1, -1};
    static constexpr int colD[4] = {1, -1, 0, 0};
    bool solve(vector<vector<char>>& board, string& word, string& comb,
               int index, int x, int y, int rows, int cols) {
        if (index == word.size())
            return true;

        for (int d = 0; d < 4; d++) {
            int adjX = x + rowD[d];
            int adjY = y + colD[d];

            if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                board[adjX][adjY] == word[index]) {
                comb.push_back(board[adjX][adjY]);
                board[adjX][adjY] = '#';
                if (solve(board, word, comb, index + 1, adjX, adjY, rows, cols))
                    return true;
                board[adjX][adjY] = comb.back();
                comb.pop_back();
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        string comb;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    comb.push_back(board[i][j]);
                    board[i][j] = '#';
                    if (solve(board, word, comb, 1, i, j, rows, cols))
                        return true;
                    board[i][j] = comb.back();
                    comb.pop_back();
                }
            }
        }

        return false;
    }
};