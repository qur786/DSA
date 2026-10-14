class Solution {
private:
    int count = 0;
    void getTotal(int n, int row, vector<bool>& cols, vector<bool>& dig,
                  vector<bool>& andig) {
        if (row == n) {
            count += 1;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || dig[col - row + n] || andig[col + row])
                continue;
            cols[col] = dig[col - row + n] = andig[col + row] = true;
            getTotal(n, row + 1, cols, dig, andig);
            cols[col] = dig[col - row + n] = andig[col + row] = false;
        }
    }

public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        getTotal(n, 0, cols, dig, andig);

        return count;
    }
};