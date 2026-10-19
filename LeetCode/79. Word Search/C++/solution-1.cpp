class Solution {
private:
    static constexpr int rowD[4] = {0, 0, 1, -1};
    static constexpr int colD[4] = {1, -1, 0, 0};
    bool solution(vector<vector<char>>& board, string word, int rows, int cols,
                  int x, int y, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int adjX = x + rowD[d];
            int adjY = y + colD[d];

            if (0 <= adjX && adjX < rows && 0 <= adjY && adjY < cols &&
                !visited[adjX][adjY] && word[index] == board[adjX][adjY]) {
                visited[adjX][adjY] = true;
                if (solution(board, word, rows, cols, adjX, adjY, index + 1,
                             visited))
                    return true;
                visited[adjX][adjY] = false;
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (solution(board, word, rows, cols, i, j, 1, visited))
                        return true;
                    visited[i][j] = false;
                }
            }
        }

        return false;
    }
};