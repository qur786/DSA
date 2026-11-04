class Solution {
private:
    void solve(int n, int row, int& count, vector<bool>& col, vector<bool>& dig,
               vector<bool>& adig) {
        if (row == n) {
            count += 1;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || dig[c - row + n] || adig[c + row])
                continue;
            col[c] = dig[c - row + n] = adig[c + row] = true;
            solve(n, row + 1, count, col, dig, adig);
            col[c] = dig[c - row + n] = adig[c + row] = false;
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> col(n, false), dig(2 * n, false), adig(2 * n, false);
        solve(n, 0, count, col, dig, adig);

        return count;
    }
};