class Solution {
private:
    vector<vector<string>> answer;
    void solveQ(vector<string>& ans, int n, int row, vector<bool>& cols,
                vector<bool>& dig, vector<bool>& andig) {
        if (row == n) {
            answer.push_back(ans);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cols[j] || dig[row - j + n] || andig[row + j])
                continue;
            cols[j] = dig[row - j + n] = andig[row + j] = true;
            ans[row][j] = 'Q';
            solveQ(ans, n, row + 1, cols, dig, andig);
            ans[row][j] = '.';
            cols[j] = dig[row - j + n] = andig[row + j] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans(n, string(n, '.'));
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        solveQ(ans, n, 0, cols, dig, andig);

        return answer;
    }
};