class Solution {
private:
    bool bin(vector<int>& row, int target) {
        int n = row.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (row[mid] == target)
                return true;
            if (row[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
    bool solve(vector<vector<int>>& matrix, int left, int right, int target) {
        if (left > right)
            return false;

        int mid = left + (right - left) / 2;

        if (target >= matrix[mid].front() && target <= matrix[mid].back())
            if (bin(matrix[mid], target))
                return true;

        return solve(matrix, left, mid - 1, target) ||
               solve(matrix, mid + 1, right, target);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1;
        return solve(matrix, 0, rows, target);
    }
};