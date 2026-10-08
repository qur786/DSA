class Solution {
private:
    int count = 0;
    void getTotalQ(int rows, int n, vector<bool>& cols, vector<bool>& dig,
                   vector<bool>& andig) {
        if (rows == n) {
            count++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (cols[j] || dig[rows - j + n] || andig[rows + j])
                continue;
            cols[j] = dig[rows - j + n] = andig[rows + j] = true;
            getTotalQ(rows + 1, n, cols, dig, andig);
            cols[j] = dig[rows - j + n] = andig[rows + j] = false;
        }
    }

public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false), dig(2 * n, false), andig(2 * n, false);
        getTotalQ(0, n, cols, dig, andig);
        return count;
    }
};