class Solution {
private:
    void solve(int& answer, vector<bool>& cols, vector<bool>& dig,
               vector<bool>& andig, int n, int row) {
        if (row == n) {
            answer += 1;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || dig[n + row - col] || andig[row + col])
                continue;
            cols[col] = dig[n + row - col] = andig[row + col] = true;
            solve(answer, cols, dig, andig, n, row + 1);
            cols[col] = dig[n + row - col] = andig[row + col] = false;
        }
    }

public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        int answer = 0;

        solve(answer, cols, dig, andig, n, 0);

        return answer;
    }
};