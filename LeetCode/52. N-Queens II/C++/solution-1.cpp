class Solution {
private:
    int count = 0;
    void getTotalQueens(int row, int n, vector<bool>& cols, vector<bool>& dig,
                        vector<bool>& andig) {
        if (row == n) {
            count += 1;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cols[j] || dig[row - j + n] || andig[row + j])
                continue;

            cols[j] = dig[row - j + n] = andig[row + j] = true;
            getTotalQueens(row + 1, n, cols, dig, andig);
            cols[j] = dig[row - j + n] = andig[row + j] = false;
        }
    }

public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        getTotalQueens(0, n, cols, dig, andig);

        return count;
    }
};