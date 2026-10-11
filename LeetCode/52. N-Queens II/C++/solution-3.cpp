class Solution {
private:
    int count = 0;
    void getTotalQueens(int n, int rows, vector<bool>& cols, vector<bool>& dig,
                        vector<bool>& andig) {
        if (rows == n) {
            count += 1;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cols[j] || dig[rows - j + n] || andig[rows + j])
                continue;
            cols[j] = dig[rows - j + n] = andig[rows + j] = true;
            getTotalQueens(n, rows + 1, cols, dig, andig);
            cols[j] = dig[rows - j + n] = andig[rows + j] = false;
        }
    }

public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        getTotalQueens(n, 0, cols, dig, andig);

        return count;
    }
};