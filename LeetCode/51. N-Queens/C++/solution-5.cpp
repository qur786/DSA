class Solution {
private:
    vector<vector<string>> answer;
    void solve(vector<string>& chess, int n, int row, vector<bool>& cols,
               vector<bool>& dig, vector<bool>& andig) {
        if (row == n) {
            answer.push_back(chess);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || dig[col - row + n] || andig[col + row])
                continue;
            cols[col] = dig[col - row + n] = andig[col + row] = true;
            chess[row][col] = 'Q';
            solve(chess, n, row + 1, cols, dig, andig);
            cols[col] = dig[col - row + n] = andig[col + row] = false;
            chess[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        solve(chess, n, 0, cols, dig, andig);
        return answer;
    }
};