class Solution {
private:
    vector<vector<string>> answer;
    void solveQ(int n, int rows, vector<string>& chess, vector<bool>& cols,
                vector<bool>& dig, vector<bool>& andig) {
        if (n == rows) {
            answer.push_back(chess);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cols[j] || dig[rows - j + n] || andig[rows + j])
                continue;

            cols[j] = dig[rows - j + n] = andig[rows + j] = true;
            chess[rows][j] = 'Q';
            solveQ(n, rows + 1, chess, cols, dig, andig);
            chess[rows][j] = '.';
            cols[j] = dig[rows - j + n] = andig[rows + j] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        solveQ(n, 0, chess, cols, dig, andig);

        return answer;
    }
};