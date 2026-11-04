class Solution {
private:
    void solve(vector<vector<string>>& answer, vector<string>& chess, int n,
               int row, vector<bool>& dig, vector<bool>& adig,
               vector<bool>& col) {
        if (row == n) {
            answer.push_back(chess);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || dig[row + c] || adig[n + row - c])
                continue;
            col[c] = dig[row + c] = adig[n + row - c] = true;
            chess[row][c] = 'Q';
            solve(answer, chess, n, row + 1, dig, adig, col);
            col[c] = dig[row + c] = adig[n + row - c] = false;
            chess[row][c] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> dig(2 * n, false), adig(2 * n, false), col(n, false);
        vector<vector<string>> answer;
        vector<string> chess(n, string(n, '.'));
        solve(answer, chess, n, 0, dig, adig, col);
        return answer;
    }
};