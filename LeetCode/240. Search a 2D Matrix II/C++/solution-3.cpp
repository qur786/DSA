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
    bool searchMat(vector<vector<int>>& matrix, int low, int high, int target) {
        if (low > high)
            return false;

        int mid = low + (high - low) / 2;

        if (target >= matrix[mid].front() && target <= matrix[mid].back()) {
            if (binarySearch(matrix[mid], target))
                return true;
        }
        return searchMat(matrix, low, mid - 1, target) ||
               searchMat(matrix, mid + 1, high, target);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMat(matrix, 0, matrix.size() - 1, target);
    }
};