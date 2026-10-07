class Solution {
private:
    vector<vector<string>> answer;
    bool isValid(vector<vector<bool>>& visited, int x, int y, int n) {
        for (int i = x - 1, j = y; i >= 0; i--) {
            if (visited[i][j])
                return false;
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (visited[i][j])
                return false;
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if (visited[i][j])
                return false;
        }

        return true;
    }
    void solveQ(vector<string>& ans, int n, int row,
                vector<vector<bool>>& visited) {
        if (row == n) {
            answer.push_back(ans);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (visited[row][j])
                continue;
            if (!isValid(visited, row, j, n))
                continue;
            visited[row][j] = true;
            ans[row][j] = 'Q';
            solveQ(ans, n, row + 1, visited);
            visited[row][j] = false;
            ans[row][j] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans(n, string(n, '.'));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        solveQ(ans, n, 0, visited);

        return answer;
    }
};