class Solution {
private:
    bool bSearch(vector<vector<int>>& matrix, int target, int left, int right) {
        if (left > right)
            return false;
        int mid = left + (right - left) / 2;

        if (matrix[mid].front() <= target && matrix[mid].back() >= target) {
            if (binary_search(matrix[mid].begin(), matrix[mid].end(), target))
                return true;
        }

        return bSearch(matrix, target, left, mid - 1) ||
               bSearch(matrix, target, mid + 1, right);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return bSearch(matrix, target, 0, matrix.size() - 1);
    }
};