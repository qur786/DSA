class Solution {
private:
    vector<vector<string>> answer;

    void solveQ(vector<string>& chess, int n, int rows, vector<bool>& cols,
                vector<bool>& dig, vector<bool>& andig) {
        if (rows == n) {
            answer.push_back(chess);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cols[j] || dig[rows - j + n] || andig[rows + j])
                continue;
            cols[j] = dig[rows - j + n] = andig[rows + j] = true;
            chess[rows][j] = 'Q';
            solveQ(chess, n, rows + 1, cols, dig, andig);
            chess[rows][j] = '.';
            cols[j] = dig[rows - j + n] = andig[rows + j] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        vector<string> chess(n, string(n, '.'));
        solveQ(chess, n, 0, cols, dig, andig);

        return answer;
    }
};