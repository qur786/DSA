class Solution {
private:
    bool binarySearch(vector<int>& row, int target) {
        int low = 0, high = row.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (row[mid] == target)
                return true;
            if (row[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
    bool searchMat(vector<vector<int>>& matrix, int target, int left,
                   int right) {
        if (left > right)
            return false;

        int mid = left + (right - left) / 2;
        if (target >= matrix[mid].front() && target <= matrix[mid].back()) {
            bool res = binarySearch(matrix[mid], target);
            if (res)
                return res;
        }

        return searchMat(matrix, target, left, mid - 1) ||
               searchMat(matrix, target, mid + 1, right);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMat(matrix, target, 0, matrix.size() - 1);
    }
};