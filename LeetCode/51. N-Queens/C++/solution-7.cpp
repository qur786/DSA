class Solution {
private:
    void solve(vector<vector<string>>& answer, vector<string>& chess,
               vector<bool>& cols, vector<bool>& dig, vector<bool>& andig,
               int n, int row) {
        if (row == n) {
            answer.push_back(chess);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || dig[n + row - col] || andig[row + col])
                continue;
            cols[col] = dig[n + row - col] = andig[row + col] = true;
            chess[row][col] = 'Q';
            solve(answer, chess, cols, dig, andig, n, row + 1);
            chess[row][col] = '.';
            cols[col] = dig[n + row - col] = andig[row + col] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        vector<vector<string>> answer;
        vector<string> chess(n, string(n, '.'));

        solve(answer, chess, cols, dig, andig, n, 0);

        return answer;
    }
};